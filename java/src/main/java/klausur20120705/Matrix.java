package klausur20120705;

public interface Matrix {
    double get(int i, int j) throws IndexOutOfBoundsException;
    void put(int i, int j, double value) throws IndexOutOfBoundsException;
}
