package beanClass;

public class MyRemark {
    private int n;
    private String email;
    private Book [] book;
    private String [] Context;
    private int [] Score;
    
    public MyRemark()
    {
    }

    public int getN() {
        return n;
    }

    public void setN(int n) {
        this.n = n;
        book = new Book[n];
        Context = new String[n];
        Score = new int[n];
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getBookName(int i) {
        return book[i].getName();
    }

    public void setBook(int i, String bookID) {
        this.book[i] = new Book();
        this.book[i].setId(bookID);
    }
    

    public String getContext(int i) {
        return Context[i];
    }

    public void setContext(int i, String Context) {
        this.Context[i] = Context;
    }

    public int getScore(int i) {
        return Score[i];
    }

    public void setScore(int i, int Score) {
        this.Score[i] = Score;
    }
}
