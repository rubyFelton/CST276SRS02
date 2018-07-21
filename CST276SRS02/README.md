# CST276SRS02
Date Validation Strategy/Template Method  


Project Name(s):  

    - GoFStrategy
    - GoFTemplateMethod
    - DateI18NEnum  
    - DateI18N  


Purposes:  

    - Learn to implement the canonical GoF Template Method Pattern.  
    - Learn to implement the canonical GoF Strategy Pattern.  
    - Learn to modify code to use the GoF Strategy and/or Template Method Pattern.  
    - Learn to choose the correct pattern.  
    - Practice citations for patterns.  
    - Learn to document code with UML class diagrams.  


Motivation Scenario:  
    
You've been asked to write a date validation function for the company Vandelay Importer Exporter Industries. You quickly write a class to handle the task.  

```
class DateValidator{...};  
```

After creating the class, your boss reminds you that you work in the Import/Export business and must handle international clients. Being in a hurry, you modify your class:  

```
class DateValidatorI18N  
{  
public:  
    enum class Format { YMD, DMY, MDY };  

    ...  
};  
```

You turn in this project and all is good... for a while. Then your boss tells you to ship something to Latvia and you look up the date format to use on Wikipedia and discover you can't handle this format:  

[Dates In Latvia, Nepal and Turkmenistan](https://en.wikipedia.org/wiki/Calendar_date#Gregorian,_year-day-month_(YDM))  

You realize the code you created to validate using an enum is not ideal and decide to apply a GoF design pattern to help make your code more flexible.  

You come up with the following interface:  

```
class IDateValidator  
{  
public:  
    virtual bool is_good(std::string const date) const = 0;  
};  
```

You start using the Strategy and Template Method patterns to handle all 4 cases as well as any unexpected future formats. 


Specification:  

    - Create an empty Visual Studio solution named CST276SRS02.  
    - Delete the CST276SRS02 project from your solution and repository.  

    - Create the 4 projects.  
    - Using GoF, implement the UML class diagram structure in C++ for GoFStrategy and GoFTemplateMethod.  

    - Create the naive class DateI18NEnum using a class enum for 3 different date formats: YMD, DMY, and MDY. Read up on C++11 class enums if you are not familiar already.  

    - Once this is working, duplicate the project code to start your DateI18N project. Apply the Strategy and/or Template Method patterns to help make the code easier to modify. 

    - Add the new YDM format to both DateI18NEnum and DateI18N projects, noting the places where you had to modify your implementation to handle the new format.  

    - In your report, note the differences between what it took to modify the code for both projects, include both pros and cons for each project design.  
    
    - Produce a UML class diagram for your DateI18NEnum and DateI18N projects. You may use any tools to help you. If you are not good with drawing tools or UML, you may sketch your class diagram on paper and show that as part of your presentation.  

    - Be sure to follow all course guidelines, especially submission of main.cpp, REPORT.md, and README.md files.  

###

