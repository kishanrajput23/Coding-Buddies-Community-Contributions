using College.App_Code;
using System;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class ManageQualifications : Form
    {
        string id;
        string type;
        public ManageQualifications(string id, string type)
        {
            InitializeComponent();
            this.id = id;
            this.type = type;
            try
            {
                bindGrid();
                txtId.Text = this.id;
            }
            catch (Exception ex)
            {

            }
        }
        public void bindGrid()
        {
            try
            {
                Qualification obj = new Qualification();
                obj.id = this.id;
                obj.type = this.type;
                DataTable dt = obj.getSpecificQualification();
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
                string degree = (string.IsNullOrWhiteSpace(txtDegree.Text)) ? "" : txtDegree.Text;
                string institute = (string.IsNullOrWhiteSpace(txtInstitute.Text)) ? "" : txtInstitute.Text;
                int year = Int32.Parse((string.IsNullOrWhiteSpace(txtYear.Text)) ? "0" : txtYear.Text);

                Qualification obj = new Qualification();
                obj.id = this.id;
                obj.degree = degree;
                obj.institute = institute;
                obj.year = year;
                obj.type = this.type;
                obj.addQualifications();
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
            txtInstitute.Text = "";
            txtDegree.Text = "";
            txtYear.Text = "0";
            txtId.Text = this.id;
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
                    string id = classGrid.SelectedRows[0].Cells[1].Value.ToString();
                    string deg = classGrid.SelectedRows[0].Cells[2].Value.ToString();
                    Qualification obj = new Qualification();
                    obj.id = id;
                    obj.degree = deg;
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
