import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTree;
import javax.swing.JTextPane;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.Font;
import java.awt.Image;
import java.awt.SystemColor;
import java.awt.Color;
import javax.swing.JProgressBar;
import javax.swing.JSpinner;
import javax.swing.JSeparator;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;

public class Questions extends JFrame {

	private JPanel contentPane;
	private int Count;
	private ListOfQuestions Ques = new ListOfQuestions();

	public Questions(Student temp, int X, int Y) {
		setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		setTitle("Questions");
		setResizable(false);
		Student S = temp;
		setBounds(X, Y, 1108, 896);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		Count = 0;
		JLabel lblIcon = new JLabel("");
		lblIcon.setBounds(12, 13, 137, 148);
		contentPane.add(lblIcon);
		
		Image img = new ImageIcon(this.getClass().getResource("/images/computer.png")).getImage();
		setIconImage(img);
		
		Image logo = new ImageIcon(this.getClass().getResource("/images/test.png")).getImage();
		lblIcon.setIcon(new ImageIcon(logo));;
		
		JSeparator separator = new JSeparator();
		separator.setBounds(12, 174, 1066, 13);
		contentPane.add(separator);
		
		JLabel lblQuestion_title = new JLabel("Question : -");
		lblQuestion_title.setFont(new Font("Arial", Font.BOLD, 30));
		lblQuestion_title.setHorizontalAlignment(SwingConstants.CENTER);
		lblQuestion_title.setBounds(66, 184, 193, 46);
		contentPane.add(lblQuestion_title);
		
		JLabel lblQuestion = new JLabel(Ques.getQuestion(Count));
		lblQuestion.setForeground(Color.ORANGE);
		lblQuestion.setFont(new Font("Tahoma", Font.PLAIN, 30));
		lblQuestion.setBounds(64, 243, 1014, 174);
		contentPane.add(lblQuestion);
		
		JLabel lblNumber = new JLabel(String.valueOf(Count+1));
		lblNumber.setForeground(Color.RED);
		lblNumber.setFont(new Font("Arial", Font.BOLD | Font.ITALIC, 25));
		lblNumber.setHorizontalAlignment(SwingConstants.CENTER);
		lblNumber.setBounds(271, 186, 56, 46);
		contentPane.add(lblNumber);
		
		JLabel lblOptions_title = new JLabel("Options :- ");
		lblOptions_title.setFont(new Font("Arial", Font.BOLD, 30));
		lblOptions_title.setHorizontalAlignment(SwingConstants.CENTER);
		lblOptions_title.setBounds(66, 444, 193, 46);
		contentPane.add(lblOptions_title);
		
		JLabel lblOptions = new JLabel(Ques.getOptions(Count));
		lblOptions.setForeground(Color.BLUE);
		lblOptions.setFont(new Font("Tahoma", Font.PLAIN, 30));
		lblOptions.setHorizontalAlignment(SwingConstants.LEFT);
		lblOptions.setBounds(64, 503, 1014, 174);
		contentPane.add(lblOptions);
		
		ButtonGroup bg = new ButtonGroup();
		JRadioButton rdbtnD = new JRadioButton("D");
		rdbtnD.setForeground(Color.GREEN);
		rdbtnD.setFont(new Font("Arial", Font.PLAIN, 20));
		rdbtnD.setBounds(844, 686, 127, 25);
		bg.add(rdbtnD);
		contentPane.add(rdbtnD);
		
		JRadioButton rdbtnC = new JRadioButton("C");
		rdbtnC.setForeground(Color.GREEN);
		rdbtnC.setFont(new Font("Arial", Font.PLAIN, 20));
		rdbtnC.setBounds(621, 686, 127, 25);
		bg.add(rdbtnC);
		contentPane.add(rdbtnC);
		
		JRadioButton rdbtnB = new JRadioButton("B");
		rdbtnB.setFont(new Font("Arial", Font.PLAIN, 20));
		rdbtnB.setForeground(Color.GREEN);
		rdbtnB.setBounds(349, 686, 127, 25);
		bg.add(rdbtnB);
		contentPane.add(rdbtnB);
		
		JRadioButton rdbtnA = new JRadioButton("A");
		rdbtnA.setFont(new Font("Arial", Font.PLAIN, 20));
		rdbtnA.setForeground(Color.GREEN);
		rdbtnA.setBounds(138, 686, 127, 25);
		bg.add(rdbtnA);
		contentPane.add(rdbtnA);
		
		JButton btnNext = new JButton("Next");
		btnNext.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnNext.setForeground(Color.BLACK);
		btnNext.setBounds(826, 766, 165, 53);
		contentPane.add(btnNext);
		
		JLabel lblEnglishQuiz = new JLabel("BBSR Odisha");
		lblEnglishQuiz.setForeground(Color.RED);
		lblEnglishQuiz.setFont(new Font("Consolas", Font.BOLD, 25));
		lblEnglishQuiz.setHorizontalAlignment(SwingConstants.CENTER);
		lblEnglishQuiz.setBounds(369, 66, 427, 39);
		contentPane.add(lblEnglishQuiz);
		
		JLabel lblCVRamanGlobalUniversity = new JLabel("C V Raman Global University");
		lblCVRamanGlobalUniversity.setForeground(Color.RED);
		lblCVRamanGlobalUniversity.setFont(new Font("Consolas", Font.BOLD, 35));
		lblCVRamanGlobalUniversity.setHorizontalAlignment(SwingConstants.CENTER);
		lblCVRamanGlobalUniversity.setBounds(161, 13, 917, 53);
		contentPane.add(lblCVRamanGlobalUniversity);
		
		JLabel lblEnglishQuiz_1 = new JLabel("English Quiz");
		lblEnglishQuiz_1.setForeground(Color.BLUE);
		lblEnglishQuiz_1.setFont(new Font("Tahoma", Font.BOLD, 30));
		lblEnglishQuiz_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblEnglishQuiz_1.setBounds(301, 118, 533, 46);
		contentPane.add(lblEnglishQuiz_1);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(208, 101, 847, 13);
		contentPane.add(separator_1);
		
		
		btnNext.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(rdbtnA.isSelected())
					S.setAnswer(Count, "A");

				if(rdbtnB.isSelected())
					S.setAnswer(Count, "B");

				if(rdbtnC.isSelected())
					S.setAnswer(Count, "C");

				if(rdbtnD.isSelected())
					S.setAnswer(Count, "D");
					
				Count++;
				bg.clearSelection();
				
				if(Count == 4) {
					btnNext.setText("Submit");
					btnNext.setForeground(Color.BLUE);
					btnNext.setBackground(Color.GREEN);
				}
				
				if(Count == 5) {
					Result frame3 = new Result(S,(int)getLocationOnScreen().getX(), (int)getLocationOnScreen().getY());
					JOptionPane.showMessageDialog(null, "Test Completed Successfully!");
					frame3.setVisible(true);
					setVisible(false);
				}
				lblQuestion.setText(Ques.getQuestion(Count));
				lblNumber.setText(String.valueOf(Count+1));
				lblOptions.setText(Ques.getOptions(Count));
				
			}
		});
			
	}
}
