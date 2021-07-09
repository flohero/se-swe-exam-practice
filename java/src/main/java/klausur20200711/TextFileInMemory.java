package klausur20200711;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class TextFileInMemory implements TextFile {
    private Map<Integer, String> lines = new HashMap<>();
    private int numberOfLines = 0;

    public TextFileInMemory(String filename) throws IOException {
        try (BufferedReader br
                     = new BufferedReader(new FileReader(filename))) {
            String line = br.readLine();
            while (line != null) {
                lines.put(numberOfLines++, line);
                line = br.readLine();
            }
        }
    }

    @Override
    public int numberOfLines() {
        return numberOfLines;
    }

    @Override
    public String lineAt(int lineNumber) {
        return lines.get(lineNumber);
    }

    @Override
    public int hashCode() {
        return lines.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof TextFileInMemory)) return false;
        return Objects.equals(lines, ((TextFileInMemory) obj).lines);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (var entry :
                lines.entrySet()) {
            sb.append(entry.getKey())
                    .append(": ")
                    .append(entry.getValue());
        }
        return sb.toString();
    }
}
