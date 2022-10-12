package com.cg.healthreminder.controller;

import static org.assertj.core.api.Assertions.assertThat;

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

import com.cg.healthreminder.model.MentalHealth;
import com.cg.healthreminder.services.MentalHealthServices;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

/**
 * @ShaniaDalal
 * 
 * This is the Test Class for MentalHealth Controller Class
 */

@RunWith(SpringRunner.class)
@WebMvcTest(value = MentalHealthController.class)
public class MentalHealthControllerTest {
	  @Autowired
	    private MockMvc mockMvc;

	    @MockBean
	    private MentalHealthServices mentalServices;
	    
	    /**
	     * Convert Object into Json String by using Jackson ObjectMapper
	     * @param ticket
	     * @return
	     * @throws JsonProcessingException
	     */
	    private String converttoJson(Object mentalHealth) throws JsonProcessingException {
	        ObjectMapper objectMapper = new ObjectMapper();
	        return objectMapper.writeValueAsString(mentalHealth);
	    }
	    
	    /**
		 * To test create MentalHealth
		 */
	    @Test
	    public void testNewMentalHealth() throws Exception{
	        String URI = "/healthreminder/addTips";
	        MentalHealth m=new MentalHealth();
			m.setMentalRating(5);
			m.setMentalTip("You need to eat chocolate");
	        String jsonInput = this.converttoJson(m);

	        Mockito.when(mentalServices.addTips(Mockito.any(MentalHealth.class))).thenReturn(m);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
	    }
	    
	    /**
		 * To test finding a Tip by Id
		 */
	    @Test
	    public void testFindByMentalRating() throws Exception{
	    	String URI = "/healthreminder/viewTips/{id}";
	        MentalHealth m=new MentalHealth();
			m.setMentalRating(5);
			m.setMentalTip("You need to eat chocolate");
	        String jsonInput = this.converttoJson(m);

	        Mockito.when(mentalServices.displayTips(Mockito.anyInt())).thenReturn(m);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI, 5).accept(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();

	        assertThat(jsonInput).isEqualTo(jsonOutput);
	    }
	    
	    /**
		 * To test updating a Tip by Id
		 */
	    @Test
	    public void testUpdateByMentalRating() throws Exception{
	        String URI = "/healthreminder/updateTips/{id}/{content}";
	        MentalHealth m=new MentalHealth();
			m.setMentalRating(5);
			m.setMentalTip("You need to eat chocolate");

	        Mockito.when(mentalServices.updateTips(Mockito.anyInt(),Mockito.anyString())).thenReturn(m);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI, 5, "try this").accept(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
	    }
	    
	    /**
		 * To test deleting a Tip by Id
		 */
	    @Test
	    public void testDeleteByMentalRating() throws Exception{
	    	String URI = "/healthreminder/deleteTips/{id}";
	        MentalHealth m=new MentalHealth();
			m.setMentalRating(5);
			m.setMentalTip("You need to eat chocolate");

	        Mockito.when(mentalServices.displayTips(Mockito.anyInt())).thenReturn(m);
	        Mockito.when(mentalServices.deleteTips(Mockito.any())).thenReturn(true);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI, 5).accept(MediaType.
	        		APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();

	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

	    }
}
