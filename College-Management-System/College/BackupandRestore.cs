using System;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace College
{
    public partial class BackupandRestore : Form
    {
        public BackupandRestore()
        {
            InitializeComponent();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                FolderBrowserDialog dlg = new FolderBrowserDialog();
                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    txtBackupText.Text = dlg.SelectedPath.ToString();

                }
            }
            catch (Exception ex)
            {
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string str = @"data source=(local)\SQLEXPRESS;database=D:\PROJJECTS\COLLEGE\COLLEGE\COLLEGE\APP_DATA\COLLEGE.MDF; integrated security = SSPI";
            SqlConnection con = new SqlConnection(str);
            con.Open();
            try
            {
                string cmd = "BACKUP DATABASE [D:\\PROJJECTS\\COLLEGE\\COLLEGE\\COLLEGE\\APP_DATA\\COLLEGE.MDF] TO DISK='" + txtBackupText.Text + "\\College" + "-" + DateTime.Now.ToString("yyyy-MM-dd-mm-ss") + ".bak'";
                using (SqlCommand command = new SqlCommand(cmd, con))
                {
                    command.ExecuteNonQuery();
                    con.Close();
                    Done d = new Done();
                    d.ShowDialog();
                    txtBackupText.Text = "";
                }

            }
            catch (Exception ex)
            {
                con.Close();
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog dlg = new OpenFileDialog();
                dlg.Filter = "SQL Server Database  Backup File | *.bak";
                dlg.Title = "Database Restore";
                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    txtRestoreText.Text = dlg.FileName;

                }
            }
            catch (Exception ex)
            {
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            string str = @"data source=(local)\SQLEXPRESS;database=D:\PROJJECTS\COLLEGE\COLLEGE\COLLEGE\APP_DATA\COLLEGE.MDF; integrated security = SSPI";
            SqlConnection con = new SqlConnection(str);
            con.Open();
            try
            {
                string st1 = string.Format("ALTER DATABASE [D:\\PROJJECTS\\COLLEGE\\COLLEGE\\COLLEGE\\APP_DATA\\COLLEGE.MDF] SET SINGLE_USER WITH ROLLBACK IMMEDIATE");
                SqlCommand s1 = new SqlCommand(st1, con);
                s1.ExecuteNonQuery();

                string st2 = string.Format("USE MASTER RESTORE DATABASE [D:\\PROJJECTS\\COLLEGE\\COLLEGE\\COLLEGE\\APP_DATA\\COLLEGE.MDF] FROM DISK='" + txtRestoreText.Text + "' WITH REPLACE");
                SqlCommand s2 = new SqlCommand(st2, con);
                s2.ExecuteNonQuery();

                string st3 = string.Format("ALTER DATABASE [D:\\PROJJECTS\\COLLEGE\\COLLEGE\\COLLEGE\\APP_DATA\\COLLEGE.MDF] SET MULTI_USER");
                SqlCommand s3 = new SqlCommand(st3, con);
                s3.ExecuteNonQuery();

                Done D = new Done();
                D.ShowDialog();

                txtRestoreText.Text = "";
            }
            catch (Exception ex)
            {
                con.Close();
                ErrorBox er = new ErrorBox();
                er.ShowDialog();
                //MessageBox.Show(ex.ToString());
            }
        }
    }
}
