// Copyright (c) 2015 CNRS
// Authors: Joseph Mirabel
//
//
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

#ifndef HPP_WHOLEBODY_STEP_TIME_DEPENDANT_PATH_HH
# define HPP_WHOLEBODY_STEP_TIME_DEPENDANT_PATH_HH

# include <hpp/core/path.hh>
# include <hpp/wholebody-step/config.hh>
# include <hpp/wholebody-step/time-dependant.hh>

namespace hpp {
  namespace wholebodyStep {
    class HPP_WHOLEBODY_STEP_DLLAPI TimeDependantPath : public core::Path
    {
      public:
        static TimeDependantPathPtr_t create (const core::PathPtr_t path)
        {
          TimeDependantPathPtr_t ptr (new TimeDependantPath (path));
          ptr->init (ptr);
          return ptr;
        }

        static TimeDependantPathPtr_t create (const core::PathPtr_t path,
            const ConstraintSetPtr_t& c)
        {
          TimeDependantPathPtr_t ptr (new TimeDependantPath (path, c));
          ptr->init (ptr);
          return ptr;
        }

        static TimeDependantPathPtr_t createCopy (const TimeDependantPath& other)
        {
          TimeDependantPathPtr_t ptr (new TimeDependantPath (other));
          ptr->initCopy (ptr);
          return ptr;
        }

        static TimeDependantPathPtr_t createCopy (const TimeDependantPath& other,
            const ConstraintSetPtr_t& c)
        {
          TimeDependantPathPtr_t ptr (new TimeDependantPath (other, c));
          ptr->initCopy (ptr);
          return ptr;
        }

        void add (const TimeDependant& td)
        {
          tds_.push_back (td);
        }

        virtual ~TimeDependantPath () throw () {}

        Configuration_t initial () const {
          return path_->initial ();
        }

        Configuration_t end () const {
          return path_->end ();
        }

        core::PathPtr_t copy () const {
          return createCopy (*this);
        }

        core::PathPtr_t copy (const ConstraintSetPtr_t& c) const {
          return createCopy (*this, c);
        }

        void setAffineTransform (const value_type& a, const value_type& b) {
          a_ = a;
          b_ = b;
        }

        void updateAbscissa (value_type t) const
        {
          const value_type y = a_*t + b_;
          for (TimeDependants_t::const_iterator it = tds_.begin ();
              it != tds_.end (); ++it)
            it->rhsAbscissa (y);
          if (constraints_ && constraints_->configProjector ())
              constraints_->configProjector ()->updateRightHandSide ();
        }

      protected:
        TimeDependantPath (const core::PathPtr_t path) :
          Path (path->timeRange (), path->outputSize (),
              path->outputDerivativeSize ()),
          path_ (path->copy ()), constraints_ (), a_ (1), b_(0)
        {}

        TimeDependantPath (const core::PathPtr_t path, const ConstraintSetPtr_t& c) :
          Path (path->timeRange (), path->outputSize (),
              path->outputDerivativeSize ()),
          path_ (path->copy ()), constraints_ (c), a_ (1), b_(0)
        {
        }

        TimeDependantPath (const TimeDependantPath &other) :
          Path (other), path_ (other.path_->copy ()),
          constraints_ (other.constraints_), a_ (other.a_), b_(other.b_)
        {}

        TimeDependantPath (const TimeDependantPath &other, const ConstraintSetPtr_t& c) :
          Path (other), path_ (other.path_->copy ()),
          constraints_ (c), a_ (other.a_), b_(other.b_)
        {
        }

        virtual bool impl_compute (ConfigurationOut_t config, value_type t) const
        {
          updateAbscissa (t);
          if (!(*path_) (config, t))
            return false;
          if (!constraints_) return true;
          return constraints_->apply (config);
        }

        void init (const TimeDependantPathPtr_t& self)
        {
          Path::init (self);
        }

        void initCopy (const TimeDependantPathPtr_t& self)
        {
          Path::initCopy (self);
        }

        virtual std::ostream& print (std::ostream& os) const {
          return os << "TimeDependantPath: " << *path_;
        }

      private:
        typedef std::vector <TimeDependant> TimeDependants_t;

        core::PathPtr_t path_;
        ConstraintSetPtr_t constraints_;
        TimeDependants_t tds_;
        value_type a_, b_;
    }; // class TimeDependantPath
  } // namespace wholebodyStep
} // namespace hpp
#endif // HPP_WHOLEBODY_STEP_TIME_DEPENDANT_PATH_HH