using College.App_Code;
using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class MarkStudentAttendance : Form
    {
        public MarkStudentAttendance()
        {
            InitializeComponent();
            try
            {
                loadBatchData();
                loadClasses();
            }
            catch (Exception ex)
            {

            }
        }
        public void loadBatchData()
        {
            try
            {
                Dictionary<string, string> test = new Dictionary<string, string>();
                Batch b = new Batch();
                DataTable dt = b.getAllBatches();
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    test.Add(dt.Rows[i][0].ToString(), dt.Rows[i][1].ToString());
                }
                cboBatch.DataSource = new BindingSource(test, null);
                cboBatch.DisplayMember = "Value";
                cboBatch.ValueMember = "Key";

                cboBatch.SelectedIndex = 0;
            }
            catch (Exception ex)
            {

            }
        }
        public void loadClasses()
        {
            try
            {
                Dictionary<string, string> test = new Dictionary<string, string>();
                ClassList b = new ClassList();
                DataTable dt = b.getAllClasses();
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    test.Add(dt.Rows[i][0].ToString(), dt.Rows[i][1].ToString());
                }
                cboClass.DataSource = new BindingSource(test, null);
                cboClass.DisplayMember = "Value";
                cboClass.ValueMember = "Key";

                cboClass.SelectedIndex = 0;
            }
            catch (Exception ex)
            {

            }
        }
        private void pictureBox2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        DataGridViewCheckBoxColumn chkP = new DataGridViewCheckBoxColumn();
        DataGridViewCheckBoxColumn chkA = new DataGridViewCheckBoxColumn();
        DataGridViewCheckBoxColumn chkL = new DataGridViewCheckBoxColumn();


        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                attGrid.Columns.Clear();
                DateTime date = DateTime.Parse(txtDate.Value.ToShortDateString());
                int currentmonth = date.Month;
                int currentyear = date.Year;
                int currentday = date.Day;

                DateTime today = date;

                int tottalDaysInMonth = System.DateTime.DaysInMonth(currentyear, currentmonth);

                DateTime dts = new DateTime(currentyear, currentmonth, currentday);

                if (dts.DayOfWeek == DayOfWeek.Sunday )
                {
                    ErrorBox error = new ErrorBox();
                    error.ShowDialog();
                }
                else
                {
                    Student tch = new Student();
                    DataTable dt = new DataTable();

                    int bCode = Int32.Parse(((KeyValuePair<string, string>)cboBatch.SelectedItem).Key);
                    int cCode = Int32.Parse(((KeyValuePair<string, string>)cboClass.SelectedItem).Key);
                    tch.batch = bCode;
                    tch.classCode = cCode;
                    dt = tch.getByBatchClassForAttendance();
                    dt.Columns.Add(new DataColumn("TODAY"));


                    foreach (DataRow dr in dt.Rows)
                    {

                        dr["TODAY"] = today.ToShortDateString();
                    }


                    if (attGrid.Columns.Contains(chkP))
                    {
                        attGrid.Columns.Remove(chkP);
                    }
                    if (attGrid.Columns.Contains(chkA))
                    {
                        attGrid.Columns.Remove(chkA);
                    }
                    if (attGrid.Columns.Contains(chkL))
                    {
                        attGrid.Columns.Remove(chkL);
                    }
                    //-------------------------------

                    attGrid.DataSource = dt;

                    //--------------------------------
                    chkP.HeaderText = "PRESENT";
                    attGrid.Columns.Insert(3, chkP);
                    //-------------------------------
                    chkA.HeaderText = "ABSENT";
                    attGrid.Columns.Insert(4, chkA);
                    //----------------------------
                    chkL.HeaderText = "LEAVE";
                    attGrid.Columns.Insert(5, chkL);
                    //------------------------------------ Get old record
                    for (int x = 0; x < dt.Rows.Count; x++)
                    {
                        string tchCode = dt.Rows[x][0].ToString();
                        Attendance at = new Attendance();
                        at.ids = tchCode;
                        at.date = today;
                        bool test = at.checkAttendance();
                        if (test)
                        {
                            string s = at.getStatus();
                            if (s.Equals("PRESENT"))
                            {
                                attGrid.Rows[x].Cells[3].Value = true;
                            }
                            else if (s.Equals("ABSENT"))
                            {
                                attGrid.Rows[x].Cells[4].Value = true;
                            }
                            else if (s.Equals("LEAVE"))
                            {
                                attGrid.Rows[x].Cells[5].Value = true;
                            }
                        }
                    }
                    //---------------
                    DataGridViewCellStyle style = new DataGridViewCellStyle();
                    attGrid.Columns[0].Width = 150;
                    attGrid.Columns[1].Width = 300;
                    attGrid.Columns[2].Width = 200;
                    attGrid.Columns[3].Width = 100;
                    attGrid.Columns[3].HeaderCell.Style.Alignment = DataGridViewContentAlignment.BottomCenter;
                    attGrid.Columns[4].Width = 100;
                    attGrid.Columns[4].HeaderCell.Style.Alignment = DataGridViewContentAlignment.BottomCenter;
                    attGrid.Columns[5].Width = 100;
                    attGrid.Columns[5].HeaderCell.Style.Alignment = DataGridViewContentAlignment.BottomCenter;

                    attGrid.Columns[0].SortMode = DataGridViewColumnSortMode.NotSortable;
                    attGrid.Columns[1].SortMode = DataGridViewColumnSortMode.NotSortable;
                    attGrid.Columns[2].SortMode = DataGridViewColumnSortMode.NotSortable;
                    attGrid.Columns[3].SortMode = DataGridViewColumnSortMode.NotSortable;
                    attGrid.Columns[4].SortMode = DataGridViewColumnSortMode.NotSortable;
                    attGrid.Columns[5].SortMode = DataGridViewColumnSortMode.NotSortable;


                    //----
                    attGrid.Columns[0].ReadOnly = true;
                    attGrid.Columns[1].ReadOnly = true;
                    attGrid.Columns[2].ReadOnly = true;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void attGrid_CurrentCellDirtyStateChanged(object sender, EventArgs e)
        {
            int row = attGrid.CurrentRow.Index;
            int col = attGrid.CurrentCell.ColumnIndex;

            if (col == 3)
            {
                attGrid[3, row].Value = "True";

                attGrid[4, row].Value = "False";
                attGrid[5, row].Value = "False";

            }
            if (col == 4)
            {
                attGrid[4, row].Value = "True";
                attGrid[3, row].Value = "False";
                attGrid[5, row].Value = "False";

            }
            if (col == 5)
            {
                attGrid[5, row].Value = "True";
                attGrid[4, row].Value = "False";
                attGrid[3, row].Value = "False";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string teacherCode;
            DateTime date = DateTime.Parse(txtDate.Value.ToShortDateString());
            int currentmonth = date.Month;
            int currentyear = date.Year;
            int currentday = date.Day;
            string status;
            string month = date.ToString("MMMM");
            int year = Int32.Parse(date.ToString("yyyy"));

            try
            {
                for (int i = 0; i < attGrid.Rows.Count; i++)
                {
                    teacherCode = attGrid.Rows[i].Cells[0].Value.ToString();

                    if (attGrid.Rows[i].Cells[3].Value.ToString() != null && attGrid.Rows[i].Cells[3].Value.ToString() == "True")
                        status = "PRESENT";
                    else if (attGrid.Rows[i].Cells[4].Value.ToString() == "True")
                        status = "ABSENT";
                    else if (attGrid.Rows[i].Cells[5].Value.ToString() == "True")
                        status = "LEAVE";
                    else
                        status = "NOT MARKED";

                    Attendance att = new Attendance();
                    att.date = date;
                    att.ids = teacherCode;
                    bool x = att.checkAttendance();
                    if (x)
                    {
                        //update
                        att.status = status;
                        att.update();
                    }
                    else
                    {
                        //insert
                        att.status = status;
                        att.type = "Student";
                        att.insert();
                    }
                }
                Done d = new Done();
                d.ShowDialog();
            }
            catch (Exception ex)
            {
                ErrorBox obj = new ErrorBox();
                obj.ShowDialog();
            }
        }
    }
}
