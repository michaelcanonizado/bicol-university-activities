public class HelloWorld {
    public static void main(String args[]) {
        float radicand = Float.parseFloat(args[0]);
        int iterations = 10;
        
        double x = radicand;
        
        // Newton-Raphson Algorithm
        /* The more iterations the
        more accurate the result will be*/
        /* Source: 
        https://surajregmi.medium.com/
        how-to-calculate-the-square-root-
        of-a-number-newton-raphson-method-
        f8007714f64*/
        System.out.print("\n");
        for (int i = 1; i <= iterations; i++) {
            x = (x + (radicand / x)) / 2;
            System.out.println(i + " iteration" + ": " + x);
        }
        System.out.print("\n");
        System.out.println("Result: " + x);
    }
}



