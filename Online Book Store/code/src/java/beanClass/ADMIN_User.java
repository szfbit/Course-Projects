package beanClass;

public class ADMIN_User {
    private int num;
    private User [] user;
    
    public ADMIN_User()
    {
    }
    
    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
        this.user = new User[num];
    }
    
    public User getUser(int i) {
        return user[i];
    }

    public void setUser(int i, String email) {
        this.user[i] =  new User();
        this.user[i].setEmail(email);
    }
}
