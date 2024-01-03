using College.App_Code;
using System;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();



            slider.Height = button5.Height;
            slider.Top = button5.Top;

            if (!panelX.Controls.Contains(controlDashboard.Instance))
            {
                panelX.Controls.Add(controlDashboard.Instance);
                controlDashboard.Instance.Dock = DockStyle.Fill;
                controlDashboard.Instance.BringToFront();
            }
            else
            {
                controlDashboard.Instance.BringToFront();
            }




            try
            {
                loadSettings();

                Employee emp = new Employee();
                emp.EmployeeId = Common.adminId;
                DataTable demp = emp.getAllEmployeeById();
                string name = demp.Rows[0][1].ToString();
                lblName.Text = name;

                if (string.IsNullOrEmpty(demp.Rows[0][5].ToString()))
                {
                    pictureBox3.Image = College.Properties.Resources._default;
                }
                else
                {
                    this.imgbytes = (Byte[])demp.Rows[0][5];
                    Image img1 = byteArrayToImage(this.imgbytes);
                    pictureBox3.Image = img1;
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }


        }
        Byte[] imgbytes;

        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }
        public void loadSettings()
        {
            try
            {
                College.App_Code.settings sets = new College.App_Code.settings();
                DataTable dt = sets.getSettings();
                College.App_Code.settings.examFee = double.Parse(dt.Rows[0][1].ToString());
                College.App_Code.settings.fine = double.Parse(dt.Rows[0][2].ToString());
                College.App_Code.settings.annualFund = double.Parse(dt.Rows[0][3].ToString());
                College.App_Code.settings.admissionFee = double.Parse(dt.Rows[0][4].ToString());
                College.App_Code.settings.address = dt.Rows[0][5].ToString();
                College.App_Code.settings.phone = dt.Rows[0][6].ToString();
                College.App_Code.settings.email = dt.Rows[0][7].ToString();
                College.App_Code.settings.institute = dt.Rows[0][8].ToString();
                lblTitle.Text = dt.Rows[0][8].ToString();
                College.App_Code.settings.moto = dt.Rows[0][9].ToString();
                lblMoto.Text = dt.Rows[0][9].ToString();
                College.App_Code.settings.logo = (Byte[])dt.Rows[0][10];
                College.App_Code.settings.logoReport = (Byte[])dt.Rows[0][11];
                College.App_Code.settings.currency = dt.Rows[0][12].ToString();



                this.imgbytes = College.App_Code.settings.logo;
                Image img1 = byteArrayToImage(this.imgbytes);

                pictureBox1.Image = img1;

            }
            catch (Exception ex)
            {

            }
        }
        private void MainForm_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            YesNo obj = new YesNo();
            obj.ShowDialog();
            if (Common.command)
                Environment.Exit(0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            slider.Height = button6.Height;
            slider.Top = button6.Top;

            if (!panelX.Controls.Contains(controlStudents.Instance))
            {
                panelX.Controls.Add(controlStudents.Instance);
                controlStudents.Instance.Dock = DockStyle.Fill;
                controlStudents.Instance.BringToFront();
            }
            else
            {
                controlStudents.Instance.BringToFront();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string time = DateTime.Now.ToString("dddd, MMMM d, yyyy [hh:mm:ss:tt]");
            lblTime.Text = time;
        }

        private void settings(object sender, EventArgs e)
        {
            slider.Height = button10.Height;
            slider.Top = button10.Top;

            if (!panelX.Controls.Contains(controlSettings.Instance))
            {
                panelX.Controls.Add(controlSettings.Instance);
                controlSettings.Instance.Dock = DockStyle.Fill;
                controlSettings.Instance.BringToFront();
            }
            else
            {
                controlSettings.Instance.BringToFront();
            }
        }

        private void expenses(object sender, EventArgs e)
        {
            slider.Height = button8.Height;
            slider.Top = button8.Top;

            if (!panelX.Controls.Contains(controlExpenses.Instance))
            {
                panelX.Controls.Add(controlExpenses.Instance);
                controlExpenses.Instance.Dock = DockStyle.Fill;
                controlExpenses.Instance.BringToFront();
            }
            else
            {
                controlExpenses.Instance.BringToFront();
            }
        }

        private void staff(object sender, EventArgs e)
        {
            slider.Height = button7.Height;
            slider.Top = button7.Top;

            if (!panelX.Controls.Contains(controlStaff.Instance))
            {
                panelX.Controls.Add(controlStaff.Instance);
                controlStaff.Instance.Dock = DockStyle.Fill;
                controlStaff.Instance.BringToFront();
            }
            else
            {
                controlStaff.Instance.BringToFront();
            }
        }

        private void changese(object sender, EventArgs e)
        {
            ChangeSecurity obj = new ChangeSecurity();
            obj.ShowDialog();
        }

        private void re(object sender, EventArgs e)
        {
            slider.Height = button9.Height;
            slider.Top = button9.Top;

            if (!panelX.Controls.Contains(controlReports.Instance))
            {
                panelX.Controls.Add(controlReports.Instance);
                controlReports.Instance.Dock = DockStyle.Fill;
                controlReports.Instance.BringToFront();
            }
            else
            {
                controlReports.Instance.BringToFront();
            }
        }

        private void das(object sender, EventArgs e)
        {
            slider.Height = button5.Height;
            slider.Top = button5.Top;

            if (!panelX.Controls.Contains(controlDashboard.Instance))
            {
                panelX.Controls.Add(controlDashboard.Instance);
                controlDashboard.Instance.Dock = DockStyle.Fill;
                controlDashboard.Instance.BringToFront();
            }
            else
            {
                controlDashboard.Instance.BringToFront();
            }
        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void backup(object sender, EventArgs e)
        {
            BackupandRestore obj = new BackupandRestore();
            obj.ShowDialog();
        }
        DBConnection strcon = new DBConnection();
        private void reset(object sender, EventArgs e)
        {

            try
            {
                YesNo ays = new YesNo();
                ays.ShowDialog();
                if (Common.command == true)
                {
                    Common.command = false;
                    Athorize a = new Athorize();
                    a.ShowDialog();
                    if (Common.command == true)
                    {
                        string[] cmds = {"Truncate table Attendance", 
                                            "Truncate table batch", 
                                            "Truncate table ClassList", 
                                            "Truncate table Fee",
                                            "Truncate table Ledger",
                                            "Truncate table payroll", 
                                            "Truncate table Qualification",
                                        "Truncate table Student"};

                        foreach (string str in cmds)
                        {
                            SqlConnection connection = strcon.connect();
                            SqlCommand cmd = new SqlCommand(str, connection);
                            cmd.ExecuteNonQuery();
                            connection.Close();
                        }
                        Done d = new Done();
                        d.ShowDialog();
                    }
                }
            }
            catch (Exception ex)
            {
                ErrorBox err = new ErrorBox();
                err.ShowDialog();
            }
        }

        private void panel5_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
