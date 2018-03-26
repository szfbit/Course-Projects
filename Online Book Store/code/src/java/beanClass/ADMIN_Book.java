package beanClass;

public class ADMIN_Book {
    private int num;
    private Book [] book;

    public ADMIN_Book()
    {
    }
    
    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
        this.book = new Book[num];
    }

    public Book getBook(int i) {
        return book[i];
    }

    public void setBook(int i, String bookID) {
        this.book[i] =  new Book();
        this.book[i].setId(bookID);
    }
}
