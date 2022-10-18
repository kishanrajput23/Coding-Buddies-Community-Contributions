using System;
using System.Data;
using System.Data.SqlClient;

namespace College.App_Code
{
    class Attendance
    {
        public int id { get; set; }
        public string ids { get; set; }
        public DateTime date { get; set; }
        public string status { get; set; }
        public string type { get; set; }
        public string month { get; set; }
        public int year { get; set; }
        DBConnection strcon = new DBConnection();
        //--------------------------------------------------
        public bool checkAttendance()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT COUNT(*) from Attendance where ids='" + this.ids + "' AND date='" + this.date + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            Int32 count = (Int32)cmd1.ExecuteScalar();
            connection.Close();
            if (count > 0)
                return true;
            else
                return false;
        }
        //--------------------------------------------------
        public string getStatus()
        {
            SqlConnection connection = strcon.connect();
            SqlCommand cmd1 = new SqlCommand();
            cmd1.CommandText = "SELECT status from Attendance where ids='" + this.ids + "' AND date='" + this.date + "'";
            cmd1.CommandType = CommandType.Text;
            cmd1.Connection = connection;
            string count = cmd1.ExecuteScalar().ToString();
            connection.Close();
            return count;
        }
        //----------------------------------------------------
        public void update()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update attendance set status=@status where ids='" + this.ids + "' AND date='" + this.date + "'";
                cmd.Parameters.AddWithValue("@status", this.status);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Error updating teacher attendace");
            }
        }
        //-------------------------------------------
        public void insert()
        {
            //insert
            try
            {

                SqlConnection connection = strcon.connect();
                string sql = "INSERT INTO Attendance(ids,date,status,type)"
                + "VALUES(@ids,@date,@status,@type)";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.Parameters.AddWithValue("@ids", this.ids);
                cmd.Parameters.AddWithValue("@date", this.date);
                cmd.Parameters.AddWithValue("@status", this.status);
                cmd.Parameters.AddWithValue("@type", this.type);
                cmd.ExecuteNonQuery();
                connection.Close();

            }
            catch (Exception ex)
            {
                throw new Exception("Could not insert attendance");
            }
        }
        //------------------------------------
        public DataTable getSessionAttendance()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT date as [Date], datename(month,date) as [Month], year(date) as [Year],status as [Status] from Attendance where ids='" + this.ids + "' AND datename(month,date)='" + this + "' AND year(date)='" + this.year + "'", connection))
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
                throw new Exception("Could not get attendance data");
            }
        }
    }
}
