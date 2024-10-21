class Thread3 implements Runnable {

  public static void main (String[] args) {
    new ThreadSimples().start();
    new Thread3().inicio();
    System.out.println("Terminando main()");
  }

  public void inicio() {
    new Thread(this).start();
  }
         
  public void run() {
    for (int i = 0; i < 10; i++) {
      try {
        Thread.sleep(500);
      } catch (InterruptedException e) {}
      System.out.println(i + " Linha Principal");
    }
  }
}

class ThreadSimples extends Thread {

  public void run() {
    for (int i = 0; i < 10; i++) {
      System.out.println(i + "Outra Linha");
      try {
        sleep(1000);
      } catch (InterruptedException e) {}
    }
    System.out.println("Terminando a Outra Linha");
  }
}

/* no video teremos: 
Terminando main()
0Outra Linha
0 Linha Principal
1 Linha Principal
1Outra Linha
2 Linha Principal
3 Linha Principal
2Outra Linha
4 Linha Principal
5 Linha Principal
3Outra Linha
6 Linha Principal
7 Linha Principal
4Outra Linha
8 Linha Principal
9 Linha Principal
5Outra Linha
6Outra Linha
7Outra Linha
8Outra Linha
9Outra Linha
Terminando a Outra Linha


*/
