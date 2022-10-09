import java.awt.EventQueue;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Color;
import javax.swing.SwingConstants;
import javax.swing.UIManager;

import java.awt.Font;
import javax.swing.JSeparator;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 * 
 * @author Rahul sharma
 *
 */
public class CGU_QuizSystem {

	private static final String RollNo = null;
	private JFrame frmQuizSystem;
	private String Names = "<html><ul><li>CSE SOFTWARE</li></ul></html>";
	// private String RollNo = "<html><ul><li>20010213</li></ul></html>";
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				

				try {
					UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
					CGU_QuizSystem window = new CGU_QuizSystem();
					window.frmQuizSystem.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public CGU_QuizSystem() {
		initialize();
	}

	private void initialize() {
		frmQuizSystem = new JFrame();
		frmQuizSystem.setResizable(false);
		frmQuizSystem.setTitle("Quiz System");
		frmQuizSystem.setBounds(500, 100, 1108, 896);
		frmQuizSystem.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmQuizSystem.getContentPane().setLayout(null);
		
		JLabel lblLogo = new JLabel("");
		lblLogo.setHorizontalAlignment(SwingConstants.CENTER);
		lblLogo.setBackground(Color.WHITE);
		lblLogo.setBounds(12, 13, 192, 187);
		frmQuizSystem.getContentPane().add(lblLogo);
		
		Image logo = new ImageIcon(this.getClass().getResource("/images/rsz_11rsz_largelogo.png")).getImage();
		
		lblLogo.setIcon(new ImageIcon(logo));
		
		JLabel lbcgu = new JLabel("C.V Raman Global University");
		lbcgu.setForeground(Color.RED);
		lbcgu.setBackground(Color.WHITE);
		lbcgu.setFont(new Font("Consolas", Font.BOLD, 35));
		lbcgu.setHorizontalAlignment(SwingConstants.CENTER);
		lbcgu.setBounds(204, 13, 862, 88);
		frmQuizSystem.getContentPane().add(lbcgu);
		
		JLabel label = new JLabel("BBSR Odisha");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setForeground(Color.RED);
		label.setFont(new Font("Consolas", Font.BOLD, 25));
		label.setBounds(429, 90, 474, 39);
		frmQuizSystem.getContentPane().add(label);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(326, 142, 635, 13);
		frmQuizSystem.getContentPane().add(separator);
		
		JLabel lblQuizSystem = new JLabel("Quiz System");
		lblQuizSystem.setHorizontalAlignment(SwingConstants.CENTER);
		lblQuizSystem.setForeground(Color.BLUE);
		lblQuizSystem.setFont(new Font("Tahoma", Font.BOLD, 90));
		lblQuizSystem.setBounds(281, 168, 640, 124);
		frmQuizSystem.getContentPane().add(lblQuizSystem);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setBounds(174, 305, 831, 13);
		frmQuizSystem.getContentPane().add(separator_1);
		
		JButton btnStart = new JButton("START");
		btnStart.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				Student_Form frame0 = new Student_Form((int)frmQuizSystem.getLocationOnScreen().getX(), (int)frmQuizSystem.getLocationOnScreen().getY());
				frame0.setVisible(true);
				frmQuizSystem.setVisible(false);
			}
		});
		btnStart.setFont(new Font("Times New Roman", Font.BOLD, 50));
		btnStart.setBounds(812, 744, 254, 88);
		frmQuizSystem.getContentPane().add(btnStart);
		
		JLabel lblNewLabel = new JLabel("Project Created by : -");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 35));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(24, 331, 331, 57);
		frmQuizSystem.getContentPane().add(lblNewLabel);
		
		/*JLabel lblName_title = new JLabel("Name");
		lblName_title.setFont(new Font("Serif", Font.PLAIN, 30));
		lblName_title.setHorizontalAlignment(SwingConstants.CENTER);
		lblName_title.setBounds(22, 423, 111, 28);
		frmQuizSystem.getContentPane().add(lblName_title);
		
		JLabel lblRollNo_title = new JLabel("Roll No.");
		lblRollNo_title.setFont(new Font("Serif", Font.PLAIN, 30));
		lblRollNo_title.setHorizontalAlignment(SwingConstants.CENTER);
		lblRollNo_title.setBounds(478, 411, 145, 28);
		frmQuizSystem.getContentPane().add(lblRollNo_title);*/
		
		JLabel lblName = new JLabel(Names);
		lblName.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblName.setBounds(22, 478, 447, 331);
		frmQuizSystem.getContentPane().add(lblName);
		
		JLabel lblRollNo = new JLabel(RollNo);
		lblRollNo.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblRollNo.setBounds(448, 454, 325, 331);
		frmQuizSystem.getContentPane().add(lblRollNo);
		
		Image img = new ImageIcon(this.getClass().getResource("/images/computer.png")).getImage();
		frmQuizSystem.setIconImage(img);

	}
}
