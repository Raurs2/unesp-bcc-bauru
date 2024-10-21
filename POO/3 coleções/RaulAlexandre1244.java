import java.util.*;

public class RaulAlexandre1244 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        scan.nextLine();

        for (int i = 0; i < n; i++) {
            String word = scan.nextLine();

            String words[] = word.split(" ");

            List<String> list = Arrays.asList(words);

           Collections.sort(list, Comparator.comparing(String::length).reversed());

            Iterator<String> it = list.iterator();

            while (it.hasNext()) {
                System.out.print(it.next());

                if (it.hasNext()) System.out.print(" ");
                else System.out.println("");
            }
                

        }

        scan.close();
    }
}
