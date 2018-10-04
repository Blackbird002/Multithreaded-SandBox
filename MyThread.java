//Use join()

class MyThread implements Runnable{
    Thread thrd;

    //Construct a new thread
    MyThread(String name){
        thrd = new Thread(this, name);
    }

    //Factory method that creastes and starts a thread
    public static MyThread createAndStart(String name){
        MyThread myThrd = new MyThread(name);

        myThrd.thrd.start(); //Starts the thread
        return myThrd;
    }

    //Entry point of thread
    public void run(){
        System.out.println(thrd.getName() + " starting.");
        try{
            for(int count = 0; count < 10; count++){
                Thread.sleep(400);
                System.out.println("In " + thrd.getName() + ", count is " + count);
            }
        }
        catch(InterruptedException exc){
            System.out.println(thrd.getName() + " interrupted!");
        }
        System.out.println(thrd.getName() + " terminated!");
    }
}