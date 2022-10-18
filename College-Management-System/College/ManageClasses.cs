using College.App_Code;
using System;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class ManageClasses : Form
    {
        public ManageClasses()
        {
            InitializeComponent();
            try
            {
                bindGrid();
            }
            catch (Exception ex)
            {

            }
        }
        public void bindGrid()
        {
            try
            {
                ClassList obj = new ClassList();
                DataTable dt = obj.getAllClasses();
                classGrid.DataSource = dt;
            }
            catch (Exception ex)
            {

            }
        }
        private void button6_Click(object sender, EventArgs e)
        {
            resetData();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string className = (string.IsNullOrWhiteSpace(txtClassName.Text)) ? "" : txtClassName.Text;
                string classCode = (string.IsNullOrWhiteSpace(txtClassCode.Text)) ? "" : txtClassCode.Text;
                double tuitionFee = double.Parse((string.IsNullOrWhiteSpace(txtTuitionFees.Text)) ? "0" : txtTuitionFees.Text);

                ClassList obj = new ClassList();
                obj.classCode = classCode;
                obj.className = className;
                obj.tuitionFee = tuitionFee;

                obj.addClass();
                Done d = new Done();
                d.ShowDialog();
                resetData();
                bindGrid();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        public void resetData()
        {
            txtClassCode.Text = "";
            txtClassName.Text = "";
            txtTuitionFees.Text = "0";
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void delete(object sender, EventArgs e)
        {
            try
            {
                YesNo o = new YesNo();
                o.ShowDialog();
                if (Common.command == true)
                {
                    int seriel = Int32.Parse(classGrid.SelectedRows[0].Cells[0].Value.ToString());
                    ClassList obj = new ClassList();
                    obj.seriel = seriel;
                    obj.delete();
                    Done d = new Done();
                    d.ShowDialog();

                    resetData();
                    bindGrid();
                }
            }
            catch (Exception ex)
            {

            }
        }
    }
}
