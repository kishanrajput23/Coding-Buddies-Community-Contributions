using System;
using System.Data;
using System.Data.SqlClient;

namespace College.App_Code
{
    class Payroll
    {
        DBConnection strcon = new DBConnection();
        private int payrollId;

        public int PayrollId
        {
            get { return payrollId; }
            set { payrollId = value; }
        }

        private string month;

        public string Month
        {
            get { return month; }
            set { month = value; }
        }
        private int year;

        public int Year
        {
            get { return year; }
            set { year = value; }
        }

        private double amount;

        public double Amount
        {
            get { return amount; }
            set { amount = value; }
        }
        private double bonuses;

        public double Bonuses
        {
            get { return bonuses; }
            set { bonuses = value; }
        }

        private double totalAmount;

        public double TotalAmount
        {
            get { return totalAmount; }
            set { totalAmount = value; }
        }

        private bool received;

        public bool Received
        {
            get { return received; }
            set { received = value; }
        }

        private DateTime date;

        public DateTime Date
        {
            get { return date; }
            set { date = value; }
        }


        private string emp;

        public string Emp
        {
            get { return emp; }
            set { emp = value; }
        }

        public int ledgerCode { get; set; }

        //-------------------
        public int paySalary()
        {
            //insert
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "INSERT INTO payroll(payroll_month,payroll_year,payroll_amount,payroll_bonuses,payroll_total_amount,payroll_received,payroll_date,payroll_emp,ledgerCode)"
                + "VALUES(@month,@year,@amount,@bonuses,@totalAmount,@received,@date,@emp,@ledgerCode)";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.Parameters.AddWithValue("@month", this.month);
                cmd.Parameters.AddWithValue("@year", this.year);
                cmd.Parameters.AddWithValue("@amount", this.amount);
                cmd.Parameters.AddWithValue("@bonuses", this.bonuses);
                cmd.Parameters.AddWithValue("@totalAmount", this.totalAmount);
                cmd.Parameters.AddWithValue("@received", this.received);
                cmd.Parameters.AddWithValue("@date", this.date);
                cmd.Parameters.AddWithValue("@emp", this.emp);
                cmd.Parameters.AddWithValue("@ledgerCode", this.ledgerCode);
                cmd.ExecuteNonQuery();
                cmd.CommandText = "SELECT @@IDENTITY";
                int value = Convert.ToInt32(cmd.ExecuteScalar());
                connection.Close();
                return value;
            }
            catch (Exception ex)
            {
                throw new Exception(ex.ToString());
            }
        }

        public bool checkPaiment()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT count(*) from payroll where payroll_month='" + this.month + "' AND payroll_year='" + this.year + "' AND payroll_emp='" + this.emp + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            int value = Int32.Parse(cmd1.ExecuteScalar().ToString());
            connection.Close();
            if (value > 0)
                return true;
            else
                return false;
        }

        public DataTable getPayrollOfYear()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from payroll where payroll_year='" + this.year + "' AND payroll_emp='" + this.emp + "'", connection))
                {
                    DataSet ds = new DataSet();
                    ds1.Fill(ds);
                    DataTable dt = new DataTable();
                    dt = ds.Tables[0];
                    connection.Close();
                    return dt;
                }
            }
            catch (Exception ex)
            {
                throw new Exception("Could not get Employee data");
            }
        }

        public void deletePayroll()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from payroll where payroll_month='" + this.month + "' AND payroll_year='" + this.year + "' AND payroll_emp='" + this.emp + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete Employee data" + ex);
            }
        }
    }
}
