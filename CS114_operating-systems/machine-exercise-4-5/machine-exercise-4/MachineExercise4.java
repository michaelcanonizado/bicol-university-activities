import java.util.Random;

class Matrix {
    private int[][] data;
    private int size;

    public Matrix(int[][] data) {
        if (data == null || data.length == 0 || data.length != data[0].length) {
            throw new IllegalArgumentException("Matrix must be non-empty and square");
        }
        this.size = data.length;
        this.data = data;
    }

    public int[][] getData() {
        return data;
    }
    public int getSize() {
        return size;
    }

    public void print() {
        /* Determine max width of any element (for alignment) */
        int maxWidth = 0;
        for (int[] row : data) {
            for (int val : row) {
                int len = String.valueOf(val).length();
                if (len > maxWidth) {
                    maxWidth = len;
                }
            }
        }

        /* Print matrix */
        for (int[] row : data) {
            System.out.print("[");
            for (int j = 0; j < row.length; j++) {
                System.out.print(String.format("%" + maxWidth + "d", row[j]));

                /* No comma for last element */
                if (j < row.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
        System.out.println();
    }
}

class MatrixUtil {
    public MatrixUtil() {}

    public Matrix generateMatrix(int size) {
        int min  = 0;
        int max = 9;

        Random rand = new Random();
        int[][] data = new int[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                data[i][j] = rand.nextInt(max - min + 1) + min;
            }
        }

        return new Matrix(data);
    }

    public Matrix multiplyMatrixSerial(Matrix a, Matrix b) {
        if (a.getSize() != b.getSize()) {
            throw new IllegalArgumentException("Matrix sizes must match");
        }

        int size = a.getSize();
        int[][] result = new int[size][size];
        int[][] dataA = a.getData();
        int[][] dataB = b.getData();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result[i][j] += dataA[i][k] * dataB[k][j];
                }
            }
        }

        return new Matrix(result);
    }

    public Matrix multiplyMatrixParallel(Matrix a, Matrix b, int numThreads) {
        if (a.getSize() != b.getSize()) {
            throw new IllegalArgumentException("Matrix sizes must match");
        }

        int size = a.getSize();
        int[][] result = new int[size][size];
        int[][] dataA = a.getData();
        int[][] dataB = b.getData();

        /* Cap the number of threads in case
           numThreads > matrix size. This prevents
           unnecessary thread creation */
        numThreads = Math.min(numThreads, size);

        /* Array to hold the threads */
        Thread[] threads = new Thread[numThreads];

        /* Row distribution (Load balancing) */
        int rowsPerThread = size / numThreads;
        /* Case size isn't divisible by thread count */
        int remainingRows = size % numThreads;

        int currentRow = 0;

        /* Assign task to each thread */
        for (int i = 0; i < numThreads; i++) {
            /* Determine which rows the thread will work on.
               And distribute the remaining rows. */
            int rowsForThisThread = rowsPerThread + (i < remainingRows ? 1 : 0);
            int endRow = currentRow + rowsForThisThread;

            final int from = currentRow;
            final int to = endRow;

            /* Create thread, assign its job, and store it in thread array */
            threads[i] = new Thread(() -> {
                for (int row = from; row < to; row++) {
                    for (int col = 0; col < size; col++) {
                        int sum = 0;
                        for (int k = 0; k < size; k++) {
                            sum += dataA[row][k] * dataB[k][col];
                        }
                        result[row][col] = sum;
                    }
                }
            });

            /* Start the thread */
            threads[i].start();
            currentRow = endRow;
        }

        try {
            /* Wait for all threads to finish */
            for (Thread t : threads) {
                t.join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        return new Matrix(result);
    }
}

public class MachineExercise4 {
    public static void main(String[] args) {
        int size = 1000;
        MatrixUtil matrixUtil = new MatrixUtil();
        System.out.printf("Generating matrix 1 of size %d\n", size);
        Matrix m1 = matrixUtil.generateMatrix(size);
        System.out.printf("Generating matrix 2 of size %d\n\n", size);
        Matrix m2 = matrixUtil.generateMatrix(size);


        /* Serial multiplication */
        long startSerial = System.nanoTime();
        Matrix productSerial = matrixUtil.multiplyMatrixSerial(m1, m2);
        long endSerial = System.nanoTime();
        double timeSerial = (endSerial - startSerial) / 1_000_000.0;
        System.out.printf("Serial multiplication took %.3f ms\n", timeSerial);

        /* Parallel multiplication */
        /* Test for different thread counts */
        int[] threadCounts = new int[]{1, 2, 4, 8};
        for (int count : threadCounts) {
            long start = System.nanoTime();
            Matrix productParallel = matrixUtil.multiplyMatrixParallel(m1, m2, count);
            long end = System.nanoTime();
            double timeParallel = (end - start) / 1_000_000.0;
            /* Calculate speedup (Amdahl's law) */
            double speedup = timeSerial / timeParallel;

            System.out.printf("Parallel multiplication with %d threads took %.3f ms (Speedup: %.2fx)\n", count, timeParallel, speedup);
        }
    }
}