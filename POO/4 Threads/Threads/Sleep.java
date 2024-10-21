import java.util.Date;

class Test {
    public static void tests() {
        try {
            Thread.sleep(30);   //sleep nao e exato
        } catch (InterruptedException e) {
        }
    }
}
class Sleep {
    public static void main(String[] args) {
        Date startTime = new Date();
        for (int i=0; i<100; i++) {
          Test.tests();
        }
        Date endTime = new Date();
        System.out.println("Tests took: " +
                           (endTime.getTime() - startTime.getTime())/1000.0  +
                           " ms");
    }
}
