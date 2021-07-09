package klausur20120705;

public class ArrayMatrix implements Matrix {
    private static final int SIZE = 10;
    private final double[] matrix = new double[SIZE * SIZE];


    @Override
    public double get(int i, int j) throws IndexOutOfBoundsException {
        return matrix[i * SIZE + j];
    }

    @Override
    public void put(int i, int j, double value) throws IndexOutOfBoundsException {
        matrix[i * SIZE + j] = value;
    }
}
