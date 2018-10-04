class JoinThreads{
    public static void main(String args[]){
        System.out.println("Main thread starting.");

        MyThread mt1 = MyThread.createAndStart("Child #1");
        MyThread mt2 = MyThread.createAndStart("Child #2");
        MyThread mt3 = MyThread.createAndStart("Child #3");

        try{
            mt1.thrd.join();    //Waits for mt1 to end
            System.out.println("Child #1 joined");
            mt2.thrd.join();    //Waits for mt2 to end
            System.out.println("Child #2 joined");
            mt3.thrd.join();    //Waits for mt3 to end
            System.out.println("Child #3 joined");
        }
        catch(InterruptedException exc){
            System.out.println("Main thread  interrupted");
        }
        System.out.println("Main thread ending.");
    }
}