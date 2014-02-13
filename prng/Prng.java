public class Prng
{
    private static final int P = 295075153; 
    private static final int[] captured = {210205973, 22795300, 58776750, 121262470, 264731963, 140842553, 242590528, 195244728, 86752752};

    private int[] nextPrng(int x, int y)
    {
        int[] prng = new int[3];
        prng[0] = (2 * x + 5) % P;
        prng[1] = (3 * y + 7) % P;
        prng[2] = prng[0] ^ prng[1];

        return prng;
    }

    public Prng()
    {
        final int F = captured[0];
        final int G = captured[1];
        long t = System.currentTimeMillis();
    
        for (int x = 0; x < P; x++) {
            int X = 0, Y = 0, Z = 0;
    
            int y = F ^ x;
            int[] prng = nextPrng(x, y);
            X = prng[0];
            Y = prng[1];
            Z = prng[2];

            if (Z == G) {
                int x1 = X, y1 = Y, X1 = 0, Y1 = 0, Z1;
                int k;
    
                for (k = 2; k < captured.length; k++) {
                    prng = nextPrng(x1, y1);
                    X1 = prng[0];
                    Y1 = prng[1];
                    Z1 = prng[2];
                    if (Z1 != captured[k]) {
                        break;
                    }
                    x1 = X1;
                    y1 = Y1;
                }
                if (k == captured.length) {
                    int X2, Y2, Z2;
                    prng = nextPrng(X1, Y1);
                    X2 = prng[0];
                    Y2 = prng[1];
                    Z2 = prng[2];
                    System.out.printf("%d -> %d\n", captured[k - 1], Z2);
                    break;
                }
            }
        }
        System.out.printf("%f seconds\n", (double)(System.currentTimeMillis() - t) / 1000.0);
    }

    public static void main(String[] argv) {
        new Prng();
    }
}
