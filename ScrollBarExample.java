import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class ScrollBarExample extends JFrame implements AdjustmentListener
{
	JLabel label,label1;
	JScrollBar s1,s2;
	Container con;

	ScrollBarExample()
	{
		setTitle("Scroll Bar Demo");
		setVisible(true);
		setSize(400,400);
		con=getContentPane();
		con.setLayout(new FlowLayout(FlowLayout.LEFT));

		label=new JLabel();
		label1=new JLabel();
		s1=new JScrollBar(JScrollBar.HORIZONTAL);
		s2=new JScrollBar(JScrollBar.VERTICAL);
		//s2.setBounds(100,500,100,500000);
		s1.addAdjustmentListener(this);
		s2.addAdjustmentListener(this);
		con.add(s1);
		con.add(s2);
		con.add(label);
		con.add(label1);

		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent we)
			{
				System.exit(0);
			}
		});
	}
	
	public void adjustmentValueChanged(AdjustmentEvent e)
	{
		label.setText("Horizontal Screen Value is : "+s1.getValue());
		label1.setText("Vertical Screen Value is : "+s2.getValue());
	}

	public static void main(String[] args) 
	{
		new ScrollBarExample();
	}
}