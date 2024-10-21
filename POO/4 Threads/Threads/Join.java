class Join {
    public static void main(String args[] ) {
        Worker[] workers = new Worker[5];

        for (int i=0; i<workers.length; i++) {
            workers[i] = new Worker(i);
            workers[i].start();
        }

        for (int i=0; i<workers.length; i++) {
            System.out.println("Esperando o trabalhador "+i);
            try {
                workers[i].join();//espera aqui até o trabalhador i terminar
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println(workers[i].getName()+" apos o Join "+i+" no main.");
        }
        System.out.println("Todos os trabalhadores terminaram.");
    }
}

class Worker extends Thread {
    int id;

    Worker(int id) {
        this.id=id;
        setName("Worker-"+id);
    }

    public void run() {
        String s = "";
        //tempo trabalhando
        for (int i=0; i<Math.random()*1000000000; i++) {
            s += i;
        }

        System.out.println("Terminando: "+this);
    }
}

