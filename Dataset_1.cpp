// #include <iostream>

// namespace PerformanceEvaluation
// {   
//     enum class Criteria {
//         TEXT = 0,
//         TITLE = 1,
//         SUBJECT = 2,
//         DATE = 3, // Publication year
//     };

//     struct Category {
//         std::string text;
//         std::string title;
//         std::string subject;
//         std::string date; 
//     };
// } // namespace PerformanceEvaluation



    // class Dataset {
    //     public:        
    //         struct dataset {
    //             std::string text;
    //             std::string title;
    //             std::string subject;
    //             std::string date; 
    //         };
            
    //         Dataset() {
    //             id++;
    //             this->dataset.text = "Text 1";
    //             this->dataset.title = "Title 1";
    //             this->dataset.subject = "Subject 1";
    //             this->dataset.date = "Date 1";
    //         }
            
    //         Dataset(std::string_view text, std::string_view title, std::string_view subject, std::string_view date) {
    //             this->id++;
    //             this->dataset.text = text;
    //             this->dataset.title = title;
    //             this->dataset.subject = subject;
    //             this->dataset.date = date;
    //         }

    //         // Dataset(const Dataset&) = delete;
    //         // Dataset(Dataset&&) = delete;
    //         // Dataset& operator=(const Dataset&) = delete;
    //         // Dataset& operator=(Dataset&&) = delete;

    //         static Dataset& getDataset() {
    //             static Dataset dataset;
    //             return dataset;
    //         } 

    //         int64_t getId() const {
    //             return id;
    //         }
            
    //         static std::string getText(const dataset& dataset) {
    //             return dataset.text;
    //         }
            
    //         static std::string getTitle(const dataset& dataset) {
    //             return dataset.title;
    //         }
            
    //         static std::string getSubject(const dataset& dataset) {
    //             return dataset.subject;
    //         }
            
    //         static std::string getDate(const dataset& dataset) {
    //             return dataset.date;
    //         }

    //     private:
    //         int64_t id;
    //         dataset dataset;
    // };

         // int32_t getId(const Dataset& dataset) const {
        //     return dataset.id;
        // }

        // std::string getText(const Dataset& dataset) const {
        //     return dataset.text;
        // }
        
        // std::string getTitle(const Dataset& dataset) const {
        //     return dataset.title;
        // }
        
        // std::string getSubject(const Dataset& dataset) const {
        //     return dataset.subject;
        // }
        
        // std::string getDate(const Dataset& dataset) const {
        //     return dataset.date;
        // }
   