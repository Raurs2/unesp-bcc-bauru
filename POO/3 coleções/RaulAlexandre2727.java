import java.util.*;

public class RaulAlexandre2727 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        TreeMap<String, Character> decode = new TreeMap<String, Character>();
        
        decode.put(".", 'a');
        decode.put("..", 'b');
        decode.put("...", 'c');
        decode.put(". .", 'd');
        decode.put(".. ..", 'e');
        decode.put("... ...", 'f');
        decode.put(". . .", 'g');
        decode.put(".. .. ..", 'h');
        decode.put("... ... ...", 'i');
        decode.put(". . . .", 'j');
        decode.put(".. .. .. ..", 'k');
        decode.put("... ... ... ...", 'l');
        decode.put(". . . . .", 'm');
        decode.put(".. .. .. .. ..", 'n');
        decode.put("... ... ... ... ...", 'o');
        decode.put(". . . . . .", 'p');
        decode.put(".. .. .. .. .. ..", 'q');
        decode.put("... ... ... ... ... ...", 'r');
        decode.put(". . . . . . .", 's');
        decode.put(".. .. .. .. .. .. ..", 't');
        decode.put("... ... ... ... ... ... ...", 'u');
        decode.put(". . . . . . . .", 'v');
        decode.put(".. .. .. .. .. .. .. ..", 'w');
        decode.put("... ... ... ... ... ... ... ...", 'x');
        decode.put(". . . . . . . . .", 'y');
        decode.put(".. .. .. .. .. .. .. .. ..", 'z');
        
        while (scan.hasNextLine()) {
            int n = Integer.parseInt(scan.nextLine());

            for (int i = 0; i < n; i++) {
                String code = scan.nextLine();

                System.out.println(decode.get(code));
            }
        }
        
        scan.close();
    }
}
