package klausur20120705;

import java.util.Collection;

public interface NDimArray<T> {
    T get(int... dimensions) throws IndexOutOfBoundsException;

    void set(T value, int... dimensions) throws IndexOutOfBoundsException;

    //or

    T get(Collection<Integer> dimensions) throws IndexOutOfBoundsException;

    void set(Collection<Integer> dimensions, T value) throws IndexOutOfBoundsException;

    //or
    // Signatur would be the same as int... dimensions
    //T get(int[] dimensions) throws IndexOutOfBoundsException;

    void set(int[] dimensions, T value) throws IndexOutOfBoundsException;
}
