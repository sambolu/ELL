////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     SupervisedExampleBuilder.h (dataset)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SupervisedExample.h"
#include "SparseEntryParser.h"

// utilities
#include "Parser.h"

// stl
#include<string>
#include <memory>

namespace dataset
{
    /// <summary> A supervised example builder. </summary>
    ///
    /// <typeparam name="VectorEntryParserType"> Type of the vector entry parser type. </typeparam>
    /// <typeparam name="DefaultDataVectorType"> Type of the default data vector type. </typeparam>
    template<typename VectorEntryParserType, typename DefaultDataVectorType> 
    class SupervisedExampleBuilder
    {
    public:

        /// <summary> Ctor. </summary>
        ///
        /// <param name="parser"> The parser. </param>
        /// <param name="hasWeight"> true if this object has weight. </param>
        SupervisedExampleBuilder(VectorEntryParserType parser, bool hasWeight = false);

        /// <summary> Takes a std::string that represents a supervised example, and returns a
        /// SupervisedExample object. </summary>
        ///
        /// <param name="spExampleString"> The sp example string. </param>
        ///
        /// <returns> A SupervisedExample. </returns>
        SupervisedExample Build(std::shared_ptr<const std::string> spExampleString);

    private:
        void HandleErrors(utilities::ParseResult result, const std::string& str);

        VectorEntryParserType _instanceParser;
        bool _hasWeight;
    };
}

#include "../tcc/SupervisedExampleBuilder.tcc"
