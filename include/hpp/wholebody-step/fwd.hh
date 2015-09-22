///
/// Copyright (c) 2014 CNRS
/// Authors: Florent Lamiraux
///
///
// This file is part of hpp-wholebody-step.
// hpp-wholebody-step-planner is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-wholebody-step-planner is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Lesser Public License for more details. You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-wholebody-step-planner. If not, see
// <http://www.gnu.org/licenses/>.

#ifndef HPP_WHOLEBODY_STEP_FWD_HH
# define HPP_WHOLEBODY_STEP_FWD_HH

# include <hpp/core/fwd.hh>
# include <hpp/walkgen/fwd.hh>
# include <hpp/wholebody-step/config.hh>
# include <hpp/constraints/symbolic-function.hh>

namespace hpp {
  namespace wholebodyStep {
    typedef model::JointPtr_t JointPtr_t;

    typedef core::EquationPtr_t EquationPtr_t;
    typedef core::NumericalConstraint NumericalConstraint;
    typedef core::NumericalConstraintPtr_t NumericalConstraintPtr_t;
    typedef core::ConstraintSet ConstraintSet;
    typedef core::ConstraintSetPtr_t ConstraintSetPtr_t;
    typedef core::ConfigProjector ConfigProjector;
    typedef core::ConfigProjectorPtr_t ConfigProjectorPtr_t;
    typedef core::DifferentiableFunctionPtr_t DifferentiableFunctionPtr_t;
    typedef core::DifferentiableFunction DifferentiableFunction;
    typedef constraints::JointFrame JointFrame;
    typedef constraints::JointFrame::Ptr_t JointFramePtr_t;
    typedef constraints::SymbolicFunction<JointFrame> JointFrameFunction;
    typedef constraints::SymbolicFunction<JointFrame>::Ptr_t JointFrameFunctionPtr_t;
    typedef constraints::PointCom PointCom;
    typedef constraints::SymbolicFunction<PointCom> PointComFunction;
    typedef constraints::SymbolicFunction<PointCom>::Ptr_t PointComFunctionPtr_t;

    typedef core::Problem Problem;
    typedef core::PathOptimizerPtr_t PathOptimizerPtr_t;

    typedef core::Path Path;
    typedef core::PathPtr_t PathPtr_t;
    typedef core::PathVector PathVector;
    typedef core::PathVectorPtr_t PathVectorPtr_t;
    typedef core::StraightPath StraightPath;
    typedef core::StraightPathPtr_t StraightPathPtr_t;

    typedef model::CenterOfMassComputationPtr_t CenterOfMassComputationPtr_t;

    typedef model::JointPtr_t JointPtr_t;
    typedef model::DevicePtr_t DevicePtr_t;
    typedef model::HumanoidRobotPtr_t HumanoidRobotPtr_t;
    typedef model::HumanoidRobot HumanoidRobot;

    typedef model::Configuration_t Configuration_t;
    typedef model::ConfigurationIn_t ConfigurationIn_t;
    typedef model::ConfigurationOut_t ConfigurationOut_t;
    typedef model::Transform3f Transform3f;
    typedef model::matrix3_t matrix3_t;
    typedef model::vector3_t vector3_t;
    typedef model::vector_t vector_t;
    typedef model::vectorOut_t vectorOut_t;
    typedef core::value_type value_type;
    typedef core::size_type size_type;

    typedef walkgen::FootPrint FootPrint;
    typedef walkgen::SplineBasedPtr_t SplineBasedPtr_t;
    typedef walkgen::SplineBased SplineBased;
    typedef walkgen::CubicBSplinePtr_t CubicBSplinePtr_t;

    HPP_PREDEF_CLASS (SmallSteps);
    typedef boost::shared_ptr <SmallSteps> SmallStepsPtr_t;
    HPP_PREDEF_CLASS (TimeDependantPath);
    typedef boost::shared_ptr <TimeDependantPath> TimeDependantPathPtr_t;
  } // namespace wholebodyStep
} // namespace hpp
#endif // HPP_WHOLEBODY_STEP_FWD_HH
