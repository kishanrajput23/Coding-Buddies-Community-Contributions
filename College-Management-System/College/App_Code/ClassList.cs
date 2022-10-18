
using System;
using System.Data;
using System.Data.SqlClient;
namespace College.App_Code
{
    class ClassList
    {
        public int seriel { get; set; }
        public string className { get; set; }
        public string classCode { get; set; }
        public double tuitionFee { get; set; }
        DBConnection strcon = new DBConnection();
        public bool checkClass()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from ClassList where className='" + this.className + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        public void addClass()
        {
            bool x = this.checkClass();
            if (x)
            {
                //update
                updateClass();
            }
            else
            {
                //insert
                try
                {
                    SqlConnection connection = strcon.connect();
                    string sql = "INSERT INTO ClassList(className,classCode,tuitionFee)"
                    + "VALUES(@className,@classCode,@tuitionFee)";
                    SqlCommand cmd = new SqlCommand(sql, connection);
                    cmd.Parameters.AddWithValue("@className", this.className);
                    cmd.Parameters.AddWithValue("@classCode", this.classCode);
                    cmd.Parameters.AddWithValue("@tuitionFee", this.tuitionFee);
                    cmd.ExecuteNonQuery();
                    connection.Close();
                }
                catch (Exception ex)
                {
                    throw new Exception("Could not insert Class data");
                }
            }

        }
        public void delete()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from ClassList Where seriel='" + this.seriel + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete class data");
            }
        }
        public void updateClass()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update ClassList set className=@className,classCode=@classCode,tuitionFee=@tuitionFee where className='" + this.className + "'";
                cmd.Parameters.AddWithValue("@className", this.className);
                cmd.Parameters.AddWithValue("@classCode", this.classCode);
                cmd.Parameters.AddWithValue("@tuitionFee", this.tuitionFee);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update Class data");
            }
        }
        public string getClassCode()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd1 = new SqlCommand();
                cmd1.CommandText = "select classCode from ClassList  where seriel='" + this.seriel + "'";
                cmd1.CommandType = CommandType.Text;
                cmd1.Connection = connection;
                string levels = cmd1.ExecuteScalar().ToString();
                connection.Close();
                return levels;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not get Code");
            }
        }

        public string getClassName()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd1 = new SqlCommand();
                cmd1.CommandText = "select className from ClassList  where seriel='" + this.seriel + "'";
                cmd1.CommandType = CommandType.Text;
                cmd1.Connection = connection;
                string levels = cmd1.ExecuteScalar().ToString();
                connection.Close();
                return levels;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not get Code");
            }
        }

        public double getTuitionFee()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd1 = new SqlCommand();
                cmd1.CommandText = "select tuitionFee from ClassList  where seriel='" + this.seriel + "'";
                cmd1.CommandType = CommandType.Text;
                cmd1.Connection = connection;
                double levels = double.Parse(cmd1.ExecuteScalar().ToString());
                connection.Close();
                return levels;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not get Code");
            }
        }
        public DataTable getAllClasses()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT  * from ClassList", connection))
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
                throw new Exception("Could not get Class data");
            }
        }
    }
}
