package br.ufu.carlosauggomes.Lab06PPI;

import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/lab06")
public class LabController {

    @Autowired
    UserRepository userRepository;
    
//    @Autowired
//    CDomainClassRepository cDomainClassRepository;
    
    
    @GetMapping(path="/add")
        public @ResponseBody String addUser (@RequestParam String name, @RequestParam String email) { 
        User n = new User(); 
        n.setName(name); 
        n.setEmail(email); 
        userRepository.save(n); 
        return "User Saved";
        }

    @GetMapping(path = "/all")
    public @ResponseBody Iterable<User> getAllUsers() {
        // This returns a JSON or XML with the users
        return userRepository.findAll();
    }
    
	@GetMapping(path="/addValid")  
	public String addValid (@Valid User user, BindingResult bindingResult) {
		if (bindingResult.hasErrors()) {   
			return"form";
		} 
		
		return "result";
	}
    
    // add Methods for the CDomainClass
    
    // addCDomainClass
    @GetMapping("/addValidDomainObject")
    public String addValidDomainObject(@Valid CDomainClass cDomainClass, BindingResult bindingResult, Model model) {
        if (bindingResult.hasErrors()){
        	//model.addAttribute("cDomainClass", cDomainClass);
        	System.out.println(cDomainClass);
        	return "form2";
        } 
        return"result";
    }
//    
//    // getAllCDomainClass
//    @GetMapping("/allCDomainClass")
//    @ResponseBody
//    public Iterable<CDomainClass> getAllCDomainClass() {
//        return cDomainClassRepository.findAll();
//    }
    
}

//Ex 10:
// A situação onde o usuario digita um nome e nao digita o email é aceitada, e não deveria acontecer

//Ex 16: Após ajustes, os resultados estão ocorrendo conforme o esperado