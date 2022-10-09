import java.awt.EventQueue;
import java.awt.Image;
import java.awt.Window;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.Font;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.border.EmptyBorder;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import java.awt.Dimension;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.JButton;
import javax.swing.border.MatteBorder;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JPasswordField;
import javax.swing.border.BevelBorder;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Student_Form extends JFrame {


	private JTextField textField_Name;
	private JTextField textField_Email;
	private JPasswordField textField_Password;
	private JTextField textField_Roll;

	public Student_Form(int X, int Y) {
		
		getContentPane().setForeground(Color.BLACK);
		setTitle("Student Form");
		setResizable(false);
		setBounds(X, Y, 1108, 896);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getContentPane().setLayout(null);
		Student S = new Student();
		JLabel Image_label = new JLabel("");
		Image_label.setBorder(null);
		Image logo = new ImageIcon(this.getClass().getResource("/images/check-form.png")).getImage();
		
		Image_label.setIcon(new ImageIcon(logo));
		
		Image img = new ImageIcon(this.getClass().getResource("/images/computer.png")).getImage();
		setIconImage(img);
		
		Image_label.setBounds(70, 13, 70, 96);
		getContentPane().add(Image_label);
		JLabel lblNewLabel = new JLabel("Fill Form Carefully");
		lblNewLabel.setBorder(null);
		lblNewLabel.setFont(new Font("Arial", Font.BOLD, 50));
		lblNewLabel.setBounds(330, 13, 511, 90);
		getContentPane().add(lblNewLabel);
		
		JSeparator separator = new JSeparator();
		separator.setBorder(null);
		separator.setBounds(39, 122, 1038, 17);
		getContentPane().add(separator);
		
		JLabel lblName = new JLabel("Name");
		lblName.setFont(new Font("Consolas", Font.BOLD, 25));
		lblName.setBounds(83, 144, 70, 24);
		getContentPane().add(lblName);
		
		textField_Name = new JTextField();
		textField_Name.setToolTipText("");
		textField_Name.setForeground(Color.BLUE);
		textField_Name.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textField_Name.setOpaque(false);
		textField_Name.setBorder(new MatteBorder(0, 0, 2, 0, (Color) Color.BLUE));
		textField_Name.setBounds(82, 190, 925, 30);
		getContentPane().add(textField_Name);
		textField_Name.setColumns(10);
		
		JLabel lblEmail = new JLabel("Email");
		lblEmail.setFont(new Font("Consolas", Font.BOLD, 25));
		lblEmail.setBounds(83, 257, 70, 24);
		getContentPane().add(lblEmail);
		
		JLabel lblCourse = new JLabel("Course");
		lblCourse.setFont(new Font("Consolas", Font.BOLD, 25));
		lblCourse.setBounds(757, 420, 84, 24);
		getContentPane().add(lblCourse);
		
		JLabel lblPassword = new JLabel("Password");
		lblPassword.setFont(new Font("Consolas", Font.BOLD, 25));
		lblPassword.setBounds(83, 602, 138, 24);
		getContentPane().add(lblPassword);
		
		JLabel lblYear = new JLabel("Year");
		lblYear.setFont(new Font("Consolas", Font.BOLD, 25));
		lblYear.setBounds(771, 506, 70, 24);
		getContentPane().add(lblYear);
		
		textField_Email = new JTextField();
		textField_Email.setForeground(Color.BLUE);
		textField_Email.setOpaque(false);
		textField_Email.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textField_Email.setColumns(10);
		textField_Email.setBorder(new MatteBorder(0, 0, 2, 0, (Color) Color.BLUE));
		textField_Email.setBounds(82, 294, 925, 30);
		getContentPane().add(textField_Email);
		
		JComboBox comboBox_Course = new JComboBox();
		comboBox_Course.setName("");
		comboBox_Course.setForeground(Color.BLUE);
		comboBox_Course.setFont(new Font("Tahoma", Font.PLAIN, 20));
		comboBox_Course.setModel(new DefaultComboBoxModel(new String[] {"B. Tech", "M. Tech", "PhD", "MCA", "MSc"}));
		comboBox_Course.setBounds(889, 408, 118, 44);
		getContentPane().add(comboBox_Course);
		
		JComboBox comboBox_Year = new JComboBox();
		comboBox_Year.setModel(new DefaultComboBoxModel(new String[] {"I", "II", "III", "IV"}));
		comboBox_Year.setForeground(Color.BLUE);
		comboBox_Year.setFont(new Font("Tahoma", Font.PLAIN, 20));
		comboBox_Year.setBounds(889, 494, 118, 44);
		getContentPane().add(comboBox_Year);
		
		JLabel lblBranch = new JLabel("Branch");
		lblBranch.setFont(new Font("Consolas", Font.BOLD, 25));
		lblBranch.setBounds(85, 514, 84, 24);
		getContentPane().add(lblBranch);
		
		JComboBox comboBox_Branch = new JComboBox();
		comboBox_Branch.setModel(new DefaultComboBoxModel(new String[] {"Civil Engineering", "Computer Science and Engineering", "Electrical Engineering", "Electronics and Communication Engineering", "Mechanical Engineering", "Chemical Engineering"}));
		comboBox_Branch.setForeground(Color.BLUE);
		comboBox_Branch.setFont(new Font("Tahoma", Font.PLAIN, 20));
		comboBox_Branch.setBounds(226, 502, 436, 44);
		getContentPane().add(comboBox_Branch);
		
		textField_Password = new JPasswordField();
		textField_Password.setOpaque(false);
		textField_Password.setBorder(new MatteBorder(0, 0, 2, 0, (Color) Color.BLUE));
		textField_Password.setForeground(Color.BLUE);
		textField_Password.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textField_Password.setBounds(222, 598, 619, 31);
		getContentPane().add(textField_Password);
		
		JButton btnClose = new JButton("CLOSE");
		btnClose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
			}
		});
		btnClose.setBorder(null);
		btnClose.setFont(new Font("Tahoma", Font.BOLD, 20));
		btnClose.setBounds(202, 736, 154, 55);
		getContentPane().add(btnClose);
		
		JButton btnNext = new JButton("PROCEED");
		btnNext.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(textField_Name.getText().isEmpty() || textField_Email.getText().isEmpty() || String.valueOf(textField_Password.getPassword()).isEmpty() || textField_Roll.getText().isEmpty()) {
					JOptionPane.showMessageDialog(null, "Incorrect Details!");
				}
				else {
				S.setName(textField_Name.getText());
				S.setEmail(textField_Email.getText());
				S.setRollNo(textField_Roll.getText());
				S.setCourse(String.valueOf(comboBox_Course.getSelectedItem()));
				S.setBranch(String.valueOf(comboBox_Branch.getSelectedItem()));
				S.setYear(String.valueOf(comboBox_Year.getSelectedItem()));
				S.setPassword(String.valueOf(textField_Password.getPassword()));
				Instruction frame1 = new Instruction(S, (int)getLocationOnScreen().getX(), (int)getLocationOnScreen().getY());
				JOptionPane.showMessageDialog(null, "Registered Successfully");
				frame1.setVisible(true);
				setVisible(false);
				}
				
			}
		});
		btnNext.setBorder(null);
		btnNext.setFont(new Font("Tahoma", Font.BOLD, 20));
		btnNext.setBounds(691, 736, 150, 55);
		getContentPane().add(btnNext);
		
		JLabel lblRollNo = new JLabel("Roll No.");
		lblRollNo.setFont(new Font("Consolas", Font.BOLD, 25));
		lblRollNo.setBounds(83, 373, 137, 24);
		getContentPane().add(lblRollNo);
		
		textField_Roll = new JTextField();
		textField_Roll.setToolTipText("");
		textField_Roll.setOpaque(false);
		textField_Roll.setForeground(Color.BLUE);
		textField_Roll.setFont(new Font("Tahoma", Font.PLAIN, 20));
		textField_Roll.setColumns(10);
		textField_Roll.setBorder(new MatteBorder(0, 0, 2, 0, (Color) Color.BLUE));
		textField_Roll.setBounds(83, 422, 460, 30);
		getContentPane().add(textField_Roll);
		
	}

}
