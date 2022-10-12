package source.clientcode;
import source.comrcoembookdonate.*;
public class Test {
    public static void main(String args[])
    {
    Book b= new Book("The Titanic", 560,"Donald Finch");
    Donor d=new Donor("Riya",1,b);
    b=null;
    System.out.println("Donor Details:");
    System.out.println("Donor name:"+d.dname);
    System.out.println("Donor Id:"+d.dId);
    System.out.println("Book Details:");
    System.out.println("Publisher:"+d.bookdonated.publisher);
    System.out.println("Title:"+d.bookdonated.title);
    System.out.println("No of pages in book:"+d.bookdonated.noOfPages);
    
    }
}
