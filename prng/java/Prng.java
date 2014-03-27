public class Prng
{
    private static final int P = 295075153; 
    private static final int[] captured = {
        210205973,
        22795300,
        58776750,
        121262470,
        264731963,
        140842553,
        242590528,
        195244728,
        86752752
    };

    private int x, y;

    private int nextPrng() {
        x = (2 * x + 5) % P;
        y = (3 * y + 7) % P;

        return x ^ y;
    }

    private boolean verify() {
        Prng q = new Prng(x, y);
        for (int k = 2; k < captured.length; k++) {
            if (q.nextPrng() != captured[k]) {
                return false;
            }
        }
        System.out.printf("%d\n", q.nextPrng());
        return true;
    }

    public Prng(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public static void findNext() {
        for (int x = 0; x < P; x++) {
            Prng p = new Prng(x, captured[0] ^ x);
            if (p.nextPrng() == captured[1] && p.verify()) {
                break;
            }
        }
    }

    public static void main(String[] argv) {
        long t = System.currentTimeMillis();
        Prng.findNext();
        System.out.printf("%f seconds\n",
                          (double)(System.currentTimeMillis() - t) / 1000.0);
    }
}
