
using System;
using System.Data;
using System.Data.SqlClient;
namespace College.App_Code
{
    class Student
    {
        public int seriel { get; set; }
        public string studentId { get; set; }
        public string name { get; set; }
        public string fatherName { get; set; }
        public string contactNumber { get; set; }
        public DateTime dob { get; set; }
        public string gender { get; set; }
        public string nic { get; set; }
        public string address { get; set; }
        public string search { get; set; }
        public string email { get; set; }
        public DateTime registrationDate { get; set; }
        public Byte[] image { get; set; }
        public int batch { get; set; }
        public int classCode { get; set; }
        public int scholarship { get; set; }
        public string maritalStatus { get; set; }
        DBConnection strcon = new DBConnection();
        //------------------------------------ = new DBConnection();
        //-------------------------------------------------------------
        public int getNextId()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = new SqlCommand("SELECT top(1) seriel from student order by seriel DESC", connection);
                int value = Convert.ToInt32(cmd.ExecuteScalar());
                value += 1;
                connection.Close();
                return value;
            }
            catch (Exception ex)
            {
                throw new Exception("Could not get seriel data" + ex);
            }
        }
        //------------- insert new student
        public void addFreshStudent()
        {
            //insert
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "INSERT INTO Student(seriel,studentId,name,fatherName,contactNumber,dob,gender,nic,address,email,registrationDate,image,batchCode,classCode,maritalStatus,scholarship)"
                + "VALUES(@seriel,@studentId,@name,@fatherName,@contactNumber,@dob,@gender,@nic,@address,@email,@registrationDate,@image,@batchCode,@classCode,@maritalStatus,@scholarship)";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.Parameters.AddWithValue("@seriel", this.seriel);
                cmd.Parameters.AddWithValue("@studentId", this.studentId);
                cmd.Parameters.AddWithValue("@name", this.name);
                cmd.Parameters.AddWithValue("@fatherName", this.fatherName);
                cmd.Parameters.AddWithValue("@contactNumber", this.contactNumber);
                cmd.Parameters.AddWithValue("@dob", this.dob);
                cmd.Parameters.AddWithValue("@gender", this.gender);
                cmd.Parameters.AddWithValue("@nic", this.nic);
                cmd.Parameters.AddWithValue("@address", this.address);
                cmd.Parameters.AddWithValue("@email", this.email);
                cmd.Parameters.AddWithValue("@registrationDate", this.registrationDate);
                cmd.Parameters.AddWithValue("@image", this.image);
                cmd.Parameters.AddWithValue("@batchCode", this.batch);
                cmd.Parameters.AddWithValue("@classCode", this.classCode);
                cmd.Parameters.AddWithValue("@maritalStatus", this.maritalStatus);
                cmd.Parameters.AddWithValue("@scholarship", this.scholarship);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not insert student data" + ex);
            }
        }
        public DataTable getStudentById()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT * from student where studentId='" + this.studentId + "'", connection))
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
                throw new Exception("Could not get student data");
            }
        }

        public DataTable getByBatchClass()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT * from student where batchCode='" + this.batch + "' AND classCode='" + this.classCode + "'", connection))
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
                throw new Exception("Could not get student data");
            }
        }
        public DataTable getByBatchClassForAttendance()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT studentId as [Student ID], name as Name from student where batchCode='" + this.batch + "' AND classCode='" + this.classCode + "'", connection))
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
                throw new Exception("Could not get student data");
            }
        }
        public void delete()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                string sql = "Delete from Student Where studentId='" + this.studentId + "'";
                SqlCommand cmd = new SqlCommand(sql, connection);
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not delete student data");
            }
        }
        public void updateStudent()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                SqlCommand cmd = connection.CreateCommand();
                cmd.CommandText = "update Student set name=@name,fatherName=@fatherName,contactNumber=@contactNumber,dob=@dob,gender=@gender,nic=@nic,address=@address,email=@email,registrationDate=@registrationDate,image=@image,batchCode=@batchCode,classCode=@classCode,maritalStatus=@maritalStatus,scholarship=@scholarship where studentId='" + this.studentId + "'";
                cmd.Parameters.AddWithValue("@name", this.name);
                cmd.Parameters.AddWithValue("@fatherName", this.fatherName);
                cmd.Parameters.AddWithValue("@contactNumber", this.contactNumber);
                cmd.Parameters.AddWithValue("@dob", this.dob);
                cmd.Parameters.AddWithValue("@gender", this.gender);
                cmd.Parameters.AddWithValue("@nic", this.nic);
                cmd.Parameters.AddWithValue("@address", this.address);
                cmd.Parameters.AddWithValue("@email", this.email);
                cmd.Parameters.AddWithValue("@registrationDate", this.registrationDate);
                cmd.Parameters.AddWithValue("@image", this.image);
                cmd.Parameters.AddWithValue("@batchCode", this.batch);
                cmd.Parameters.AddWithValue("@classCode", this.classCode);
                cmd.Parameters.AddWithValue("@maritalStatus", this.maritalStatus);
                cmd.Parameters.AddWithValue("@scholarship", this.scholarship);
                cmd.CommandType = CommandType.Text;
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            catch (Exception ex)
            {
                throw new Exception("Could not update Class data" + ex);
            }
        }
        //-------------- get student
        public DataTable searchSudent()
        {
            try
            {
                SqlConnection connection = strcon.connect();
                using (SqlDataAdapter ds1 = new SqlDataAdapter("SELECT studentId as [Student ID],name as [Name],fatherName as [Father Name],contactNumber as [Contact Number],email as [Email] from student where studentId like '%" + this.search + "%' OR name like '%" + this.search + "%'", connection))
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
                throw new Exception("Could not get student data");
            }
        }

    }
}
