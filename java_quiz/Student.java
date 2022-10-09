
public class Student {
	private String Name;
	private String Email;
	private String Course;
	private String Year;
	private String Branch;
	private String Password;
	private String RollNo;
	private String Answer[] = new String[5];
	
	public Student() {
		for(int i=0; i<5; i++)
			Answer[i] = " ";
	}
	private int Marks = 0;
	
	public void setName(String s) {
		Name = s;
	}
	public String getName() {
		return Name;
	}
	public void setEmail(String s) {
		Email = s;
	}
	public String getEmail() {
		return Email;
	}
	public void setRollNo(String s) {
		RollNo = s;
	}
	public String getRollNo() {
		return RollNo;
	}
	public void setCourse(String s) {
		Course = s;
	}
	public String getCourse() {
		return Course;
	}
	public void setYear(String s) {
		Year = s;
	}
	public String getYear() {
		return Year;
	}
	public void setBranch(String s) {
		Branch = s;
	}
	public String getBranch() {
		return Branch;
	}
	public void setPassword(String s) {
		Password = s;
	}
	public String getPassword() {
		return Password;
	}
	public void setAnswer(int i, String s) {
		Answer[i] = s;
	}
	public String getAnswer(int i) {
		return Answer[i];
	}
	public void Check(String s[]) {
		for(int i = 0; i<5 ; i++) {
			if(Answer[i].equals(s[i]))
				Marks++;
		}
	}
	
	public int getMarks() {
		return Marks;
	}
	
}
