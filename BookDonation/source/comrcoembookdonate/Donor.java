package source.comrcoembookdonate;

public class Donor 
{
    public String dname;
    public int dId;
    public Book bookdonated;

    public Donor(String dname, int dId, Book bookdonated )
    {
        this.dname=dname;
        this.dId=dId;
        this.bookdonated=bookdonated;
    }
   
    public String getDname() {
        return dname;
    }
    public int getdId() {
        return dId;
    }
    public Book getBookdonated() {
        return bookdonated;
    }
    public void setDname(String dname) {
        this.dname = dname;
    }
    public void setdId(int dId) {
        this.dId = dId;
    }
    public void setBookdonated(Book bookdonated) {
        this.bookdonated=bookdonated;
    }
 
}
