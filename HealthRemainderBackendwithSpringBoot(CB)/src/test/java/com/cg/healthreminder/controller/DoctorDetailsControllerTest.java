/**
 * @AnkitBanerjee
 * 
 * This is the Controller Testing Class for Alarm Module.
*/
package com.cg.healthreminder.controller;

import com.cg.healthreminder.model.DoctorDetails;
import com.cg.healthreminder.services.DoctorDetailsService;
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
@WebMvcTest(value = DoctorDetailsController.class)
public class DoctorDetailsControllerTest {

	@Autowired
    private MockMvc mockMvc;

    @MockBean
    private DoctorDetailsService doctorDetailsService;
    
    
    /**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param doctor
     * @return
     * @throws JsonProcessingException
     */
    private String converttoJson(Object doctor) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(doctor);
    }
    
    /**
	 * 
	 * To check if we able to create new Doctor Details
	*/
    @Test
    public void testNewDoctorDetails() throws Exception{
        String URI = "/doctor/createDoctor";
        DoctorDetails doctor= new DoctorDetails();
        doctor.setDoctorId(103);
        doctor.setDoctorName("Dr Ankit");
        doctor.setDoctorSpec("Dentist");
        doctor.setDoctorCertFile("Certified Doctor");
        doctor.setVerfStatus(true);
        String jsonInput = this.converttoJson(doctor);

        Mockito.when(doctorDetailsService.createDoctor(Mockito.any(DoctorDetails.class))).thenReturn(doctor);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
	
    /**
	 * 
	 * To check if we able to find Doctor Details by Doctor Id
	*/
    @Test
    public void testFindDoctorById() throws Exception{
        String URI = "/doctor/getDoctorById/{doctorId}";
        DoctorDetails doctor= new DoctorDetails();
        doctor.setDoctorId(103);
        doctor.setDoctorName("Dr Ankit");
        doctor.setDoctorSpec("Dentist");
        doctor.setDoctorCertFile("Certified Doctor");
        doctor.setVerfStatus(true);

		String jsonInput = this.converttoJson(doctor);

        Mockito.when(doctorDetailsService.findDoctorById(Mockito.anyInt())).thenReturn(doctor);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 103).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    /**
	 * 
	 * To check if we able to find Doctor Details by Doctor Specialization
	*/
    @Test
    public void testFindDoctorBySpec() throws Exception{
        String URI = "/doctor/getDoctorBySpec/{doctorSpec}";
        DoctorDetails doctor= new DoctorDetails();
        doctor.setDoctorId(103);
        doctor.setDoctorName("Dr Ankit");
        doctor.setDoctorSpec("Dentist");
        doctor.setDoctorCertFile("Certified Doctor");
        doctor.setVerfStatus(true);

		String jsonInput = this.converttoJson(doctor);

        Mockito.when(doctorDetailsService.findDoctorBySpec(Mockito.anyString())).thenReturn(doctor);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, "Dentist").accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
    
    /**
	 * 
	 * To check if we able to delete Doctor Details by Doctor Id
	*/
    @Test
    public void testDeleteDoctorById() throws Exception{
    	 String URI = "/doctor/deleteDoctorById/doctor/{doctorId}";  
    	 DoctorDetails doctor= new DoctorDetails();
         doctor.setDoctorId(103);
         doctor.setDoctorName("Dr Ankit");
         doctor.setDoctorSpec("Dentist");
         doctor.setDoctorCertFile("Certified Doctor");
         doctor.setVerfStatus(true);

        Mockito.when(doctorDetailsService.findDoctorById(Mockito.anyInt())).thenReturn(doctor);
        Mockito.when(doctorDetailsService.deleteDoctorById(Mockito.anyInt())).thenReturn(doctor);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,103).accept(MediaType.
        		APPLICATION_JSON)).andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

    }
    
    
    
    
}
