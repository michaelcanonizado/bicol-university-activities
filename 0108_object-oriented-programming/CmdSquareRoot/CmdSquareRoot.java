public class CmdSquareRoot {
    public static void main(String args[]) {
        float radicand = Float.parseFloat(args[0]);
        int iterations = 10;
        
        double x = radicand;
        
        // Newton-Raphson Algorithm
        /*Source: 
        https://surajregmi.medium.com/
        how-to-calculate-the-square-root-
        of-a-number-newton-raphson-method-
        f8007714f64*/
        for (int i = 0; i < iterations; i++) {
            x = (x + (radicand / x)) / 2;
            System.out.println("x" + i + ": " + x);
        }
    }
}


