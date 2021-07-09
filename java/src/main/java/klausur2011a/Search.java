package klausur2011a;

import java.util.Iterator;
import java.util.Objects;

public class Search {
    public static <T> Iterator<T> search(Iterator<T> it, T value) {
        while(it.hasNext()) {
            if(Objects.equals(it.next(), value)) {
                return it;
            }
        }
        return null;
    }
}
