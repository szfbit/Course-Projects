package beanClass;

public class Remark {
    private int num;
    private String [] email;
    private int [] star;
    private String [] remark;

    public Remark()
    {
    }
    
    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
        email = new String[num];
        star = new int[num];
        remark = new String[num];
    }

    public String getEmail(int i) {
        return email[i];
    }

    public void setEmail(int i, String email) {
        this.email[i] = new String(email);
    }

    public int getStar(int i) {
        return star[i];
    }

    public void setStar(int i, int star) {
        this.star[i] = star;
    }

    public String getRemark(int i) {
        return remark[i];
    }

    public void setRemark(int i, String remark) {
        this.remark[i] = new String(remark);
    }
    
    
    
}
