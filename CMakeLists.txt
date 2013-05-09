cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

rosbuild_gensrv()
INCLUDE_DIRECTORIES(
    src
    src/Core
    src/Models/MOMDP
    src/Bounds
    src/Algorithms
    src/Algorithms/SARSOP
    src/MathLib
    src/Parser
    src/Parser/Cassandra
    src/Parser/POMDPX
    src/Utils
    src/OfflineSolver
    src/Evaluator
    src/Simulator
    src/Controller
)

# source files for the appl lib
# Maybe a glob could be possible
rosbuild_add_library(appl_lib
    src/PolicyGraph/PolicyGraph.cpp
    src/PolicyGraph/PolicyGraphGenerator.cpp
    src/Evaluator/EvaluationEngine.cpp
    src/Evaluator/EvaluatorSampleEngine.cpp
    src/Simulator/SimulationEngine.cpp
    src/MathLib/DenseVector.cpp
    src/MathLib/MathLib.cpp
    src/MathLib/SparseMatrix.cpp
    src/MathLib/SparseVector.cpp
    src/Algorithms/SARSOP/BinManager.cpp
    src/Algorithms/SARSOP/BinManagerSet.cpp
    src/Algorithms/SARSOP/Sample.cpp
    src/Algorithms/SARSOP/SampleBP.cpp
    src/Algorithms/SARSOP/SARSOP.cpp
    src/Algorithms/SARSOP/SARSOPPrune.cpp
    src/Models/MOMDP/StateTransitionX.cpp
    src/Models/MOMDP/IVariable.cpp
    src/Models/MOMDP/BooleanVariable.cpp
    src/Models/MOMDP/BeliefTransitionMOMDPLite.cpp
    src/Models/MOMDP/Variable.cpp
    src/Models/MOMDP/IVariableValue.cpp
    src/Models/MOMDP/StateTransitionXY.cpp
    src/Models/MOMDP/MOMDP.cpp
    src/Models/MOMDP/StateTransitionXXpY.cpp
    src/Models/MOMDP/VariableRelation.cpp
    src/Models/MOMDP/StateTransitionY.cpp
    src/Models/MOMDP/VariableValue.cpp
    src/Models/MOMDP/VariableCombined.cpp
    src/Models/MOMDP/MOMDPLite.cpp
    src/Models/MOMDP/Rewards.cpp
    src/Models/MOMDP/ObservationProbabilities.cpp
    src/Models/MOMDP/BeliefTransitionMOMDP.cpp
    src/OfflineSolver/GlobalResource.cpp
    src/OfflineSolver/solverUtils.cpp
    src/Bounds/AlphaPlane.cpp
    src/Bounds/AlphaPlanePool.cpp
    src/Bounds/AlphaPlanePoolSet.cpp
    src/Bounds/AlphaVectorPolicy.cpp
    src/Bounds/BackupAlphaPlaneMOMDP.cpp
    src/Bounds/BackupAlphaPlaneMOMDPLite.cpp
    src/Bounds/BackupBeliefValuePairMOMDP.cpp
    src/Bounds/BackupBeliefValuePairMOMDPLite.cpp
    src/Bounds/BeliefValuePair.cpp
    src/Bounds/BeliefValuePairPool.cpp
    src/Bounds/BeliefValuePairPoolSet.cpp
    src/Bounds/BlindLBInitializer.cpp
    src/Bounds/FastInfUBInitializer.cpp
    src/Bounds/FullObsUBInitializer.cpp
    src/Bounds/PruneAlphaPlane.cpp
    src/Bounds/PruneBeliefValuePair.cpp
    src/Bounds/xml_parse_lib.c
    src/Core/Actions.cpp
    src/Core/VariableContainer.cpp
    src/Core/Belief.cpp
    src/Core/BeliefCache.cpp
    src/Core/BeliefException.cpp
    src/Core/BeliefForest.cpp
    src/Core/BeliefTreeNode.cpp
    src/Core/BeliefWithState.cpp
    src/Core/MObject.cpp
    src/Core/Observations.cpp
    src/Core/States.cpp
    src/Core/UniqueBeliefHeap.cpp
    src/Parser/Cassandra/Parser.cpp
    src/Parser/Cassandra/POMDP.cpp
    src/Parser/Cassandra/pomdpCassandraWrapper.cpp
    src/Parser/ParserSelector.cpp
    src/Parser/POMDPX/FactoredPomdp.cpp
    src/Parser/POMDPX/Function.cpp
    src/Parser/POMDPX/ObsAct.cpp
    src/Parser/POMDPX/PreCEntry.cpp
    src/Parser/POMDPX/PreCMatrix.cpp
    src/Parser/POMDPX/SparseEntry.cpp
    src/Parser/POMDPX/SparseTable.cpp
    src/Parser/POMDPX/State.cpp
    src/Parser/POMDPX/StateObsAct.cpp
    src/Parser/POMDPX/tinystr.cpp
    src/Parser/POMDPX/tinyxml.cpp
    src/Parser/POMDPX/tinyxmlerror.cpp
    src/Parser/POMDPX/tinyxmlparser.cpp
    src/Utils/InfoLog.cpp
    src/Utils/md5.cpp
    src/Utils/md5wrapper.cpp
    src/Utils/CPMemUtils.cpp
    src/Utils/StatsCollector.cpp
    src/Utils/SimulationRewardCollector.cpp
    src/Parser/Cassandra/include/pomdp_spec.tab.cc
    src/Parser/Cassandra/include/pomdp_spec.yy.cc
    src/miniposix/getopt.c
    src/miniposix/getopt1.c
    src/miniposix/getopt_init.c
    src/Parser/Cassandra/decision-tree.c
    src/Parser/Cassandra/imm-reward.c
    src/Parser/Cassandra/mdpCassandra.c
    src/Parser/Cassandra/parse_err.c
    src/Parser/Cassandra/parse_hash.c
    src/Parser/Cassandra/sparse-matrix.c
    src/Controller/Controller.cpp
)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services


#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
rosbuild_add_executable(controlpipe src/Controller/controlpipe.cpp)
target_link_libraries(controlpipe appl_lib)

