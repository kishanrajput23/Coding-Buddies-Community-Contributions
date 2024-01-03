using College.App_Code;
using System;
using System.Data;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace College
{
    public partial class Login : Form
    {
        public Login()
        {
            InitializeComponent();
            loadImage();
        }
        Byte[] imgbytes;
        public Image byteArrayToImage(byte[] byteArrayIn)
        {
            MemoryStream ms = new MemoryStream(byteArrayIn);
            Image returnImage = Image.FromStream(ms);
            return returnImage;
        }
        public void loadImage()
        {
            try
            {
                College.App_Code.settings sets = new College.App_Code.settings();
                DataTable dt = sets.getSettings();
                College.App_Code.settings.logo = (Byte[])dt.Rows[0][10];

                this.imgbytes = College.App_Code.settings.logo;
                Image img1 = byteArrayToImage(this.imgbytes);

                pictureBox1.Image = img1;
            }
            catch (System.Exception ex)
            {

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string id = txtId.Text;
                string pwd = txtPwd.Text;
                pwd = StringCipher.Encrypt("collegedatabase", pwd);
                Employee emp = new Employee();
                emp.LoginId = id;
                emp.LoginPwd = pwd;
                bool x = emp.checkEmployeeLogin();
                if (x)
                {
                    string adminId = emp.getEmpId();
                    Common.adminId = adminId;
                    emp.EmployeeId = adminId;
                    string admin = emp.getCredentials();
                    Common.des = admin;
                    this.Hide();
                    MainForm db = new MainForm();
                    db.ShowDialog();
                }
                else
                {
                    ErrorBox error = new ErrorBox();
                    error.ShowDialog();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
    }
}
