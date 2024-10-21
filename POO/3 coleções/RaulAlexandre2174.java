import java.util.*;

public class RaulAlexandre2174 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        TreeSet<String> namePoke = new TreeSet<>();
        
        int nPoke = Integer.parseInt(scan.nextLine());

        for (int i = 0; i < nPoke; i++) {
            namePoke.add(scan.nextLine());
        }

        System.out.printf("Falta(m) %d pomekon(s).\n", 151 - namePoke.size());

        scan.close();
    }
}
