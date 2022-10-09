
public class ListOfQuestions {
	private String Ques1 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;<b>Number of primitive data types in Java are?</b>  </html>";
	
	private String Ques2 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;<b>What is the size of float and double in java?</b>    </html>";
	
	private String Ques3 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;<b><i>\"Automatic type conversion is possible in which of the possible cases?\"</i></b> "
			+ "<br/><br/>&nbsp;&nbsp;&nbsp;&nbsp;In this statement <i><b>\'Himanshu\'</b></i> is which part of speech?";
	
	private String Ques4 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;<b><i>\"Prakash is running.\"</i></b> "
			+ "<br/> <br/>&nbsp;&nbsp;&nbsp;&nbsp;In this statement <i><b>\'running\'</b></i> is which part of speech?";
	private String Ques5 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;<b><i>\"Kuldeep is Student. He likes Science.\"</i>"
			+ "</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;In this statement <i><b>\'He\'</b></i> is which part of speech?";
	
	private String Opt1 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;A. <b>6</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;B. <b>7</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;C. <b>8</b>"
			+ 				" <br/>&nbsp;&nbsp;&nbsp;&nbsp;D. <b>9</b></html>";
	private String Opt2 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;A. <b>32 and 64</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;B. <b>32 and 32</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;"
			+ "C. <b>64 and 64</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;D. <b>64 and 32</b></html>";
	private String Opt3 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;A. <b>Verb</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;B. <b>Adjective</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;C. "
						+ "<b>Noun</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;D. <b>Pronoun</b> </html>";
	private String Opt4 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;A. <b>Verb</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;B. <b>Adjective</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;"
			+ "C. <b>Noun</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;D. <b>Pronoun</b> </html>";
	private String Opt5 = "<html>&nbsp;&nbsp;&nbsp;&nbsp;A. <b>Verb</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;B. <b>Adjective</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;"
			+ "C. <b>Noun</b> <br/>&nbsp;&nbsp;&nbsp;&nbsp;D. <b>Pronoun</b> </html>";
	
	private String[] Answer = {"C", "A", "C", "A", "D"};
	
	public String getQuestion(int i) {
		if(i == 0)
			return Ques1;
		else if(i == 1)
			return Ques2;
		else if(i == 2)
			return Ques3;
		else if(i == 3)
			return Ques4;
		else if(i == 4)
			return Ques5;
		
		return "";
	}
	public String getOptions(int i) {
		if(i == 0)
			return Opt1;
		else if(i == 1)
			return Opt2;
		else if(i == 2)
			return Opt3;
		else if(i == 3)
			return Opt4;
		else if(i == 4)
			return Opt5;
		
		return "";
	}
	public String[] getAnswer() {
		return Answer;
	}
}
