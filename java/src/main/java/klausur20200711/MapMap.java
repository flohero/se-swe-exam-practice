package klausur20200711;

import java.util.HashMap;
import java.util.Map;

public class MapMap<K1, K2> {
    private final Map<K1, K2> map1 = new HashMap<>();
    private final Map<K2, K1> map2 = new HashMap<>();

    public void put(K1 k1, K2 k2) {
        map1.put(k1, k2);
        map2.put(k2, k1);
    }

    public K2 get2(K1 k1) {
        return map1.get(k1);
    }

    public K1 get1(K2 k2) {
        return map2.get(k2);
    }
}
