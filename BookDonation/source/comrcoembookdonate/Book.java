package source.comrcoembookdonate;
public class Book
{
    public String title;
    public int noOfPages;
    public String publisher;
   public Book(String title, int noOfPages,String publisher)
   {
       this.title=title;
       this.noOfPages=noOfPages;
       this.publisher=publisher;
   }
   public String getBookTitle() {
    return title;
}
public int getNoOfPages() {
    return noOfPages;
}
public String getPublisher() {
    return publisher;
}

public void setBookTitle(String bookTitle) {
    this.title = bookTitle;
}
public void setNoOfPages(int noOfPages) {
    this.noOfPages = noOfPages;
}
public void setPublisher(String publisher) {
    this.publisher = publisher;
}
  
} 