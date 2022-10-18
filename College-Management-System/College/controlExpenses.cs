using College.App_Code;
using System;
using System.Data;
using System.Windows.Forms;

namespace College
{
    public partial class controlExpenses : UserControl
    {
        private static controlExpenses _instance;
        public static controlExpenses Instance
        {
            get
            {
                if (_instance == null)
                {
                    _instance = new controlExpenses();
                }
                return _instance;
            }
        }

        public controlExpenses()
        {
            InitializeComponent();
            txtDate.Value = DateTime.Parse(DateTime.Now.ToShortDateString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                string id = (string.IsNullOrWhiteSpace(txtId.Text)) ? "" : txtId.Text;
                if (id.Length == 0)
                {
                    //insert
                    string reason = (string.IsNullOrWhiteSpace(txtReason.Text)) ? "" : txtReason.Text;
                    string note = (string.IsNullOrWhiteSpace(txtNote.Text)) ? "" : txtNote.Text;
                    string type = cboTypes.Text;
                    DateTime date = DateTime.Parse(txtDate.Value.ToShortDateString());
                    double amount = double.Parse((string.IsNullOrWhiteSpace(txtAmount.Text)) ? "0.0." : txtAmount.Text);

                    //---------------------------- update ledger
                    Ledger led = new Ledger();
                    led.date = DateTime.Parse(txtDate.Value.ToShortDateString());
                    led.reason = reason;
                    led.note = note;
                    led.amount = amount;
                    led.type = cboTypes.Text;
                    led.addLedger();

                    ledgerGrid.DataSource = null;
                    Done d = new Done();
                    d.ShowDialog();

                    resetData();
                }
                else
                {
                    //update
                    string reason = (string.IsNullOrWhiteSpace(txtReason.Text)) ? "" : txtReason.Text;
                    string note = (string.IsNullOrWhiteSpace(txtNote.Text)) ? "" : txtNote.Text;
                    string type = cboTypes.Text;
                    DateTime date = DateTime.Parse(txtDate.Value.ToShortDateString());
                    double amount = double.Parse((string.IsNullOrWhiteSpace(txtAmount.Text)) ? "0.0." : txtAmount.Text);

                    //---------------------------- update ledger
                    Ledger led = new Ledger();
                    led.id = Int32.Parse(id);
                    led.date = DateTime.Parse(txtDate.Value.ToShortDateString());
                    led.reason = reason;
                    led.note = note;
                    led.amount = amount;
                    led.type = cboTypes.Text;
                    led.updateLedger();

                    ledgerGrid.DataSource = null;
                    Done d = new Done();
                    d.ShowDialog();

                    resetData();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }
        DataTable dx = null;
        public void resetData()
        {
            try
            {
                txtId.Text = "";
                cboTypes.SelectedIndex = 0;
                txtAmount.Text = "0";
                txtDate.Value = DateTime.Parse(DateTime.Now.ToShortDateString());
                txtNote.Text = "";
                txtReason.SelectedItem = 0;

                ledgerGrid.DataSource = null;
                calculateAmount();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                SelectDate obj = new SelectDate();
                obj.ShowDialog();
                if (Common.command == true)
                {
                    DateTime date = Common.date;
                    Ledger l = new Ledger();
                    l.date = date;
                    DataTable dt = l.getLedgerByDate();
                    ledgerGrid.DataSource = dt;

                    calculateAmount();
                }
            }
            catch (Exception ex)
            {

            }
        }
        double debit = 0;
        double credit = 0;
        double balance = 0;
        public void calculateAmount()
        {
            debit = 0;
            credit = 0;
            balance = 0;
            string type;
            for (int i = 0; i < ledgerGrid.Rows.Count; i++)
            {
                type = ledgerGrid.Rows[i].Cells[1].Value.ToString();
                if (type.Equals("Debit"))
                    debit += double.Parse(ledgerGrid.Rows[i].Cells[2].Value.ToString());
                else
                    credit += double.Parse(ledgerGrid.Rows[i].Cells[2].Value.ToString());
            }
            balance = credit - debit;
            lblDebit.Text = debit.ToString();
            lblCredit.Text = credit.ToString();
            lblBalance.Text = balance.ToString();
        }
        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void mothly(object sender, EventArgs e)
        {
            try
            {
                SelectMonth b = new SelectMonth();
                b.ShowDialog();
                if (Common.command == true)
                {
                    Ledger l = new Ledger();
                    l.month = Common.month;
                    l.year = Common.year;
                    DataTable dt = l.getByMonth();
                    ledgerGrid.DataSource = dt;

                    calculateAmount();
                }
            }
            catch (Exception ex)
            {

            }
        }

        private void ledgerGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                if (ledgerGrid.Rows.Count > 0)
                {
                    string type = ledgerGrid.SelectedRows[0].Cells[3].Value.ToString();
                    if (type.Equals("Expenditure") || type.Equals("Others"))
                    {
                        int ledgerCode = Int32.Parse(ledgerGrid.SelectedRows[0].Cells[0].Value.ToString());
                        double amount = double.Parse(ledgerGrid.SelectedRows[0].Cells[2].Value.ToString());
                        string pType = ledgerGrid.SelectedRows[0].Cells[1].Value.ToString();
                        string note = ledgerGrid.SelectedRows[0].Cells[5].Value.ToString();
                        DateTime date = DateTime.Parse(ledgerGrid.SelectedRows[0].Cells[4].Value.ToString());
                        txtDate.Value = date;
                        txtId.Text = ledgerCode.ToString();
                        txtAmount.Text = amount.ToString();
                        txtNote.Text = note;


                        int i = 0;
                        foreach (string g in cboTypes.Items)
                        {
                            if (g == pType)
                            {
                                cboTypes.SelectedIndex = i;
                            }
                            i++;
                        }


                        i = 0;
                        foreach (string g in txtReason.Items)
                        {
                            if (g == type)
                            {
                                txtReason.SelectedIndex = i;
                            }
                            i++;
                        }
                    }
                    else
                    {
                        txtId.Text = "";
                        cboTypes.SelectedIndex = 0;
                        txtAmount.Text = "0";
                        txtDate.Value = DateTime.Parse(DateTime.Now.ToShortDateString());
                        txtNote.Text = "";
                        txtReason.SelectedItem = 0;
                    }
                }
                else
                {
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void reset(object sender, EventArgs e)
        {
            resetData();
        }
    }
}
