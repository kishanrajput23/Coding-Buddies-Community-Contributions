import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JSeparator;
import javax.swing.SwingConstants;
import javax.swing.JCheckBox;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Result extends JFrame {

	private JPanel contentPane;

	public Result(Student temp, int X, int Y) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Result");
		setResizable(false);
		Student S = temp;
		setBounds(X, Y, 1108, 896);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		/*Image img = new ImageIcon(this.getClass().getResource("/images/computer.png")).getImage();
		setIconImage(img);*/
		
		JLabel lblIcon = new JLabel("");
		lblIcon.setBounds(12, 0, 280, 278);
		contentPane.add(lblIcon);
		Image logo = new ImageIcon(this.getClass().getResource("/images/rsz_21rsz_largelogo.png")).getImage();
		lblIcon.setIcon(new ImageIcon(logo));
		ListOfQuestions Ques = new ListOfQuestions();
		S.Check(Ques.getAnswer());
		JLabel lblNewLabel = new JLabel("RESULT");
		lblNewLabel.setForeground(Color.BLUE);
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setFont(new Font("Arial", Font.BOLD, 40));
		lblNewLabel.setBounds(319, 161, 683, 90);
		contentPane.add(lblNewLabel);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(22, 280, 1056, 10);
		contentPane.add(separator);
		
		JLabel lblName = new JLabel("Name");
		lblName.setFont(new Font("Consolas", Font.BOLD, 25));
		lblName.setBounds(27, 317, 68, 39);
		contentPane.add(lblName);
		
		JLabel lblName_Field = new JLabel("");
		lblName_Field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblName_Field.setText(S.getName());
		lblName_Field.setBounds(169, 319, 751, 36);
		contentPane.add(lblName_Field);
		
		JLabel lblCourse = new JLabel("Course");
		lblCourse.setFont(new Font("Consolas", Font.BOLD, 25));
		lblCourse.setBounds(632, 389, 106, 39);
		contentPane.add(lblCourse);
		
		JLabel lblCourse_field = new JLabel("");
		lblCourse_field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblCourse_field.setText(S.getCourse());
		lblCourse_field.setBounds(797, 387, 245, 39);
		contentPane.add(lblCourse_field);
		
		JLabel lblYear = new JLabel("Year");
		lblYear.setFont(new Font("Consolas", Font.BOLD, 25));
		lblYear.setBounds(632, 462, 106, 39);
		contentPane.add(lblYear);
		
		JLabel lblYear_field = new JLabel("");
		lblYear_field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblYear_field.setText(S.getYear());
		lblYear_field.setBounds(818, 463, 200, 33);
		contentPane.add(lblYear_field);
		
		JLabel lblBranch = new JLabel("Branch");
		lblBranch.setFont(new Font("Consolas", Font.BOLD, 25));
		lblBranch.setBounds(22, 457, 106, 39);
		contentPane.add(lblBranch);
		
		JLabel lblBranch_field = new JLabel("");
		lblBranch_field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblBranch_field.setText(S.getBranch());
		lblBranch_field.setBounds(169, 464, 451, 36);
		contentPane.add(lblBranch_field);
		
		JLabel lblRollNo = new JLabel("Roll No.");
		lblRollNo.setFont(new Font("Consolas", Font.BOLD, 25));
		lblRollNo.setBounds(22, 393, 118, 35);
		contentPane.add(lblRollNo);
		
		JLabel lblRollNo_field = new JLabel("");
		lblRollNo_field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblRollNo_field.setText(S.getRollNo());
		lblRollNo_field.setBounds(169, 390, 225, 39);
		contentPane.add(lblRollNo_field);
		
		JLabel lblMarks = new JLabel("Marks");
		lblMarks.setForeground(Color.BLUE);
		lblMarks.setFont(new Font("Consolas", Font.BOLD, 25));
		lblMarks.setBounds(206, 554, 106, 39);
		contentPane.add(lblMarks);
		
		JLabel lblMarks_field = new JLabel("");
		lblMarks_field.setForeground(Color.GREEN);
		lblMarks_field.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblMarks_field.setText(String.valueOf(S.getMarks()));
		lblMarks_field.setBounds(381, 554, 151, 39);
		contentPane.add(lblMarks_field);
		
		JButton btnClose = new JButton("Close");
		btnClose.setFont(new Font("Tahoma", Font.PLAIN, 20));
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		btnClose.setBounds(797, 748, 157, 67);
		contentPane.add(btnClose);
		
		JLabel label = new JLabel("C V Raman Global University");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setForeground(Color.RED);
		label.setFont(new Font("Consolas", Font.BOLD, 30));
		label.setBounds(289, 13, 801, 67);
		contentPane.add(label);
		
		JLabel label_1 = new JLabel("BBSR Odisha");
		label_1.setHorizontalAlignment(SwingConstants.CENTER);
		label_1.setForeground(Color.RED);
		label_1.setFont(new Font("Consolas", Font.BOLD, 25));
		label_1.setBounds(446, 82, 427, 39);
		contentPane.add(label_1);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(313, 134, 765, 13);
		contentPane.add(separator_1);
	}
}
