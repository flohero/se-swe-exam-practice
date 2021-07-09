package klausur20120705;

import java.util.ArrayList;
import java.util.List;

public class ListMatrix implements Matrix{
    private static final int SIZE = 10;
    private final List<Double> matrix = new ArrayList<>(SIZE * SIZE);

    @Override
    public double get(int i, int j) throws IndexOutOfBoundsException {
        return matrix.get(i * SIZE + j);
    }

    @Override
    public void put(int i, int j, double value) throws IndexOutOfBoundsException {
        matrix.set(i * SIZE + j, value);
    }
}
