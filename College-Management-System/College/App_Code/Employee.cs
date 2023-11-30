
using System;
using System.Data;
using System.Data.SqlClient;

namespace College.App_Code
{
    class Employee
    {
        DBConnection strcon = new DBConnection();
        private string employeeId;

        public string EmployeeId
        {
            get { return employeeId; }
            set { employeeId = value; }
        }

        private string employeeName;

        public string EmployeeName
        {
            get { return employeeName; }
            set { employeeName = value; }
        }


        private string email;

        public string Email
        {
            get { return email; }
            set { email = value; }
        }

        private string phoneNo;

        public string PhoneNo
        {
            get { return phoneNo; }
            set { phoneNo = value; }
        }
        private string address;

        public string Address
        {
            get { return address; }
            set { address = value; }
        }

        private byte[] image;

        public byte[] Image
        {
            get { return image; }
            set { image = value; }
        }

        private double basicSalary;

        public double BasicSalary
        {
            get { return basicSalary; }
            set { basicSalary = value; }
        }

        private string loginId;

        public string LoginId
        {
            get { return loginId; }
            set { loginId = value; }
        }

        private string loginPwd;

        public string LoginPwd
        {
            get { return loginPwd; }
            set { loginPwd = value; }
        }
        private string designation;

        public string Designation
        {
            get { return designation; }
            set { designation = value; }
        }
        public string designation2 { get; set; }
        private bool active;

        public bool Active
        {
            get { return active; }
            set { active = value; }
        }
        //-------------------------------------------------------------------------------------------
        public string getName()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT employee_name from employee where employee_id='" + this.EmployeeId + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            string value = cmd1.ExecuteScalar().ToString();
            connection.Close();
            return value;
        }
        //-------------------------------------------------------------------------------------------
        public double getSalary()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT employee_basic_salary from employee where employee_id='" + this.EmployeeId + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            double value = double.Parse(cmd1.ExecuteScalar().ToString());
            connection.Close();
            return value;
        }
        //-------------------------------------------------------------------------------------------
        public string getEmpId()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT employee_id from employee where employee_login_id='" + this.loginId + "' and employee_login_password='" + this.loginPwd + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            string value = cmd1.ExecuteScalar().ToString();
            connection.Close();
            return value;
        }
        public string getCredentials()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT designation2 from employee where employee_id='" + this.employeeId + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            string value = cmd1.ExecuteScalar().ToString();
            connection.Close();
            return value;
        }
        public bool checkEmployeeLogin()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from employee where employee_login_id='" + this.loginId + "' and employee_login_password='" + this.loginPwd + "' AND employee_active='True'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        //------------------------------------
        public bool checkEmployee()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from employee where employee_id='" + this.employeeId + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        public void insertEmployee()
        {
            bool x = this.checkEmployee();
            if (x)
            {
                //update
                YesNo ays = new YesNo();
                ays.ShowDialog();
                if (Common.command == true)
                {
                    //update
                    updateEmployee();
                }
                else
                {
                    return;
                }
            }
            else
            {
                //insert
                try
                {
                    SqlConnection connection = strcon.connect();
                    string sql = "INSERT INTO employee(employee_id,employee_name,employee_email,employee_phone_no,employee_address,employee_basic_salary,employee_login_id,employee_login_password,employee_designation,employee_active,employee_picture,designation2)"
                    + "VALUES(@employee_id,@employee_name,@employee_email,@employee_phone_no,@employee_address,@employee_basic_salary,@employee_login_id,@employee_login_password,@employee_designation,@employee_active,@image,@designation2)";
                    SqlCommand cmd = new SqlCommand(sql, connection);
                    cmd.Parameters.AddWithValue("@employee_id", this.employeeId);
                    cmd.Parameters.AddWithValue("@employee_name", this.employeeName);
                    cmd.Parameters.AddWithValue("@employee_email", this.email);
                    cmd.Parameters.AddWithValue("@employee_phone_no", this.phoneNo);
                    cmd.Parameters.AddWithValue("@employee_address", this.address);
                    cmd.Parameters.AddWithValue("@employee_basic_salary", this.basicSalary);
                    cmd.Parameters.AddWithValue("@employee_login_id", this.loginId);
                    cmd.Parameters.AddWithValue("@employee_login_password", this.loginPwd);
                    cmd.Parameters.AddWithValue("@employee_designation", this.designation);
                    cmd.Parameters.AddWithValue("@employee_active", this.active);
                    cmd.Parameters.AddWithValue("@image", this.image);
                    cmd.Parameters.AddWithValue("@designation2", this.designation2);
                    cmd.ExecuteNonQuery();
                    connection.Close();
                }
                catch (Exception ex)
                {
                    throw new Exception("Could not insert employee data" + ex);
                }
            }

        }
        public void updateEmployee()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update employee set employee_name=@name,employee_email=@email,employee_phone_no=@phoneNo,employee_address=@address,employee_basic_salary=@basicSalary,employee_designation=@designation,employee_active=@active,employee_picture=@employee_picture,designation2=@designation2 where employee_id='" + this.employeeId + "'";
                cmd.Parameters.AddWithValue("@name", this.employeeName);
                cmd.Parameters.AddWithValue("@email", this.email);
                cmd.Parameters.AddWithValue("@phoneNo", this.phoneNo);
                cmd.Parameters.AddWithValue("@address", this.address);
                cmd.Parameters.AddWithValue("@basicSalary", this.basicSalary);
                cmd.Parameters.AddWithValue("@designation", this.designation);
                cmd.Parameters.AddWithValue("@active", this.active);
                cmd.Parameters.AddWithValue("@employee_picture", this.image);
                cmd.Parameters.AddWithValue("@designation2", this.designation2);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update employee data");
            }
        }
        public void updateLoginId()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update employee set employee_login_id=@id where employee_id='" + this.employeeId + "'";
                cmd.Parameters.AddWithValue("@id", this.loginId);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update employee data");
            }
        }
        public void updatePassword()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update employee set employee_login_password=@id where employee_id='" + this.employeeId + "'";
                cmd.Parameters.AddWithValue("@id", this.loginPwd);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update employee data");
            }
        }
        public DataTable getAllEmployeeById()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from employee where employee_id='" + this.employeeId + "'", connection))
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
        public DataTable getAllEmployee()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  employee_id as [Employee ID],employee_name as [Name],employee_email as [Email],employee_phone_no as [Phone No],employee_address as [Address],employee_designation as [Designation],designation2 as [User Role] from employee", connection))
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

        public void deleteEmployee()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from employee Where employee_id='" + this.employeeId + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete Employee data");
            }
        }

        public void reset()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update employee set employee_login_id=@loginid,employee_login_password=@loginpwd where employee_id='" + this.employeeId + "'";
                cmd.Parameters.AddWithValue("@loginid", this.loginId);
                cmd.Parameters.AddWithValue("@loginpwd", this.loginPwd);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update employee data");
            }
        }


    }
}
