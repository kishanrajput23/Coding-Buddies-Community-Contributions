package com.cg.healthreminder.controller;

import com.cg.healthreminder.model.FollowUpMentalRatingInfo;
import com.cg.healthreminder.services.FollowUpMentalRatingInfoServices;
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

/**
 * @ParthGoel
 *
 * This is the test class for Follow Up Mental Rating Information controller
 */

@RunWith(SpringRunner.class)
@WebMvcTest(value = FollowUpMentalRatingInfoController.class)
public class FollowUpMentalRatingInfoControllerTest {

	@Autowired
    private MockMvc mockMvc;
	
	@MockBean
    private FollowUpMentalRatingInfoServices followUpMentalRatingInfoServices;
	
	/**
     * Convert Object into Json String by using Jackson ObjectMapper
     * @param ticket
     * @return
     * @throws JsonProcessingException
     */
	
	private String converttoJson(Object followUpMentalRatingInfo) throws JsonProcessingException {
        ObjectMapper objectMapper = new ObjectMapper();
        return objectMapper.writeValueAsString(followUpMentalRatingInfo);
    }
	
	@Test
    public void testCreateMentalRating() throws Exception{
        String URI = "/healthreminder/create_followup_mentalrating";
        FollowUpMentalRatingInfo followUpMentalRatingInfo = new FollowUpMentalRatingInfo();
        followUpMentalRatingInfo.setPatientId(1);
        followUpMentalRatingInfo.setMentalRating(5);
		
        String jsonInput = this.converttoJson(followUpMentalRatingInfo);

        Mockito.when(followUpMentalRatingInfoServices.createMentalRating(Mockito.any(FollowUpMentalRatingInfo.class))).thenReturn(followUpMentalRatingInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();
        assertThat(jsonInput).isEqualTo(jsonOutput);
        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
    }
	
	@Test
    public void testFindMentalRatingById() throws Exception{
        String URI = "/healthreminder/followup_mentalrating_find/{patientId}";
        FollowUpMentalRatingInfo followUpMentalRatingInfo = new FollowUpMentalRatingInfo();
        followUpMentalRatingInfo.setPatientId(1);
        followUpMentalRatingInfo.setMentalRating(5);
		
		String jsonInput = this.converttoJson(followUpMentalRatingInfo);

        Mockito.when(followUpMentalRatingInfoServices.findMentalRatingById(Mockito.anyInt())).thenReturn(followUpMentalRatingInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 1).accept(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }
	
	@Test
    public void testDeleteMentalRating() throws Exception{
    	String URI = "/healthreminder/delete_mentalrating_by_id/{patientId}";  
    	FollowUpMentalRatingInfo followUpMentalRatingInfo = new FollowUpMentalRatingInfo();
        followUpMentalRatingInfo.setPatientId(1);
        followUpMentalRatingInfo.setMentalRating(5);

        Mockito.when(followUpMentalRatingInfoServices.findMentalRatingById(Mockito.anyInt())).thenReturn(followUpMentalRatingInfo);
        Mockito.when(followUpMentalRatingInfoServices.deleteMentalRating(Mockito.any())).thenReturn(true);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI,1).accept(MediaType.
        		APPLICATION_JSON)).andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

    }
	
	@Test
    public void testUpdateMentalRatingById() throws Exception{

        String URI = "/healthreminder/followup_mentalrating_update/{patientId}/rating/{MentalRating}";
        FollowUpMentalRatingInfo followUpMentalRatingInfo = new FollowUpMentalRatingInfo();
        followUpMentalRatingInfo.setPatientId(1);
        followUpMentalRatingInfo.setMentalRating(5);
        
        String jsonInput = this.converttoJson(followUpMentalRatingInfo);

        Mockito.when(followUpMentalRatingInfoServices.updateMentalRatingById(Mockito.any(),Mockito.anyInt())).thenReturn(followUpMentalRatingInfo);
        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.put(URI, 1, 4).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
                .andReturn();
        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
        String jsonOutput = mockHttpServletResponse.getContentAsString();

        assertThat(jsonInput).isEqualTo(jsonOutput);
    }




	

}
