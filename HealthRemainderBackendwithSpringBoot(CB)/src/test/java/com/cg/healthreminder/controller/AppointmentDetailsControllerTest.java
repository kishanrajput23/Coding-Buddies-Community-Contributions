/**
 * @SayantanDas
 * 
 * This is the Controller Testing Class for AppointmentDetails.
*/

package com.cg.healthreminder.controller;
import com.cg.healthreminder.model.AppointmentDetails;
import com.cg.healthreminder.services.AppointmentDetailsServices;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.mock.web.MockHttpServletResponse;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;

import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@WebMvcTest(value = AppointmentDetailsController.class)
public class AppointmentDetailsControllerTest {
	  @Autowired
	    private MockMvc mockMvc;

	    @MockBean
	    private AppointmentDetailsServices appointmentDetailsService;
	    
	    /**
	     * Convert Object into Json String by using Jackson ObjectMapper
	     * @param appointmentDetails
	     * @return
	     * @throws JsonProcessingException
	     */
	    private String converttoJson(Object appointmentDetails) throws JsonProcessingException {
	        ObjectMapper objectMapper = new ObjectMapper();
	        return objectMapper.writeValueAsString(appointmentDetails);
	    }
	    
	    
	    /**
		 * 
		 * To check if a new appointment gets created
		*/
	    @Test
	    public void testNewAppointment() throws Exception{
	        String URI = "/healthreminder/createAppointment";
	        AppointmentDetails apd = new AppointmentDetails();
	        apd.setAppId(1);
		    apd.setDoctorId(5);
			apd.setDoctorName("DoctorAstin");
			apd.setDoctorStartTime("12:00");
			apd.setDoctorEndTime("9:00");
			apd.setDoctorDate("12/16/2020"); 
			apd.setPatientName("Sayantan");
			apd.setPatientId(4);
	        String jsonInput = this.converttoJson(apd);

	        Mockito.when(appointmentDetailsService.createAppointment(Mockito.any(AppointmentDetails.class))).thenReturn(apd);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();
	        assertThat(jsonInput).isEqualTo(jsonOutput);
	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
	    }
	    
	    
	    /**
		 * 
		 * Check if able to find Appointment by PatientId.
		*/
	    @Test
	    public void testFindByPatientId() throws Exception{
	        String URI = "/healthreminder/findAppointmentByPatId/{patientId}";
	        AppointmentDetails apd = new AppointmentDetails();
	        apd.setAppId(1);
		    apd.setDoctorId(5);
			apd.setDoctorName("DoctorAstin");
			apd.setDoctorStartTime("12:00");
			apd.setDoctorEndTime("9:00");
			apd.setDoctorDate("12/16/2020"); 
			apd.setPatientName("Sayantan");
			apd.setPatientId(4);

			String jsonInput = this.converttoJson(apd);

	        Mockito.when(appointmentDetailsService.findAppointmentDetailByPatientId(Mockito.anyInt())).thenReturn(apd);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 4).accept(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();

	        assertThat(jsonInput).isEqualTo(jsonOutput);
	    }
	    
	    
	    /**
		 * 
		 * Check if able to find Appointment by DoctorId.
		*/
	    @Test
	    public void testFindByDoctorId() throws Exception{
	        String URI = "/healthreminder/findAppointmentByDocId/{doctorId}";
	        AppointmentDetails apd = new AppointmentDetails();
	        apd.setAppId(1);
		    apd.setDoctorId(5);
			apd.setDoctorName("DoctorAstin");
			apd.setDoctorStartTime("12:00");
			apd.setDoctorEndTime("9:00");
			apd.setDoctorDate("12/16/2020"); 
			apd.setPatientName("Sayantan");
			apd.setPatientId(4);

			String jsonInput = this.converttoJson(apd);

	        Mockito.when(appointmentDetailsService.findAppointmentDetailByDoctorId(Mockito.anyInt())).thenReturn(apd);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 5).accept(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();

	        assertThat(jsonInput).isEqualTo(jsonOutput);
	    }
	    
	    
	    
	    /**
		 * 
		 * Check if able to delete Appointment by PatientId.
		*/
	    @Test
	    public void testDeleteAppointmentByPatientId() throws Exception{
	    	 String URI = "/healthreminder/deleteAppointmentByPatId/{patientId}";  
	    	 AppointmentDetails apd = new AppointmentDetails();
		      apd.setAppId(1);
			  apd.setDoctorId(5);
			  apd.setDoctorName("DoctorAstin");
			  apd.setDoctorStartTime("12:00");
			  apd.setDoctorEndTime("9:00");
			  apd.setDoctorDate("12/16/2020"); 
			  apd.setPatientName("Sayantan");
			  apd.setPatientId(4);

	        Mockito.when(appointmentDetailsService.findAppointmentDetailByPatientId(Mockito.anyInt())).thenReturn(apd);
	        Mockito.when(appointmentDetailsService.deleteAppointmentByPatientId(Mockito.anyInt())).thenReturn(apd);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,4).accept(MediaType.
	        		APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

	    }
	    
	    
	    /**
		 * 
		 *Check if able to delete Appointment by DoctorId.
		*/
	    @Test
	    public void testDeleteAppointmenttByDoctorId() throws Exception{
	    	 String URI = "/healthreminder/deleteAppointmentByDocId/{doctorId}";  
	    	 AppointmentDetails apd = new AppointmentDetails();
		      apd.setAppId(1);
			  apd.setDoctorId(5);
			  apd.setDoctorName("DoctorAstin");
			  apd.setDoctorStartTime("12:00");
			  apd.setDoctorEndTime("9:00");
			  apd.setDoctorDate("12/16/2020"); 
			  apd.setPatientName("Sayantan");
			  apd.setPatientId(4);

	        Mockito.when(appointmentDetailsService.findAppointmentDetailByDoctorId(Mockito.anyInt())).thenReturn(apd);
	        Mockito.when(appointmentDetailsService.deleteAppointmentByDoctorId(Mockito.anyInt())).thenReturn(apd);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,4).accept(MediaType.
	        		APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

	    }

}
